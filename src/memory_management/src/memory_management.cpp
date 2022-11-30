#include <memory_management/memory_management.h>


using namespace std;

MemoryManagement::MemoryManagement(ros::NodeHandle &nh):
nh_(nh)
{
   _memory_command_subscriber = nh.subscribe("/memory_command", 10, &MemoryManagement::memoryCommandCallback, this);
}


void MemoryManagement::memoryCommandCallback(const std_msgs::String::ConstPtr& message)
{
    _memory_command.data = message->data;
    ROS_INFO("Memory command from ROS Topic: %s", _memory_command.data.c_str());
}


void MemoryManagement::prepareTestData()
{
    for(unsigned int i=0; i<512; i++)
    {
        _test_data._items[i] = i;
    }

    _test_data._size = 10;
    _test_data._data_points = new float[_test_data._size];

    for(unsigned int i=0; i<_test_data._size; i++)
    {
        _test_data._data_points[i] = (float)i * (1000.0);
    }

    for(unsigned int i=0; i<_test_data._size; i++)
    {
        printf("data point value %d: %f\n", i, _test_data._data_points[i]);   
    }

    _memory_buffer = (char *)malloc(sizeof(_test_data) + 512 + sizeof(float) * _test_data._size + 200);
    _memory_command.data = "";
    _memory_buffer_is_removed = false;
}


void MemoryManagement::readMemory(Data *target, char *buffer)
{
    memcpy(target, buffer, sizeof(Data));
    for(int i=0;i<target->_size; i++)
    {
        printf("Target Data Points[%d]: %f\n", i, target->_data_points[i]);
    }

    printf("\n");
    
    target->_data_points = (float *)malloc(target->_size * sizeof(float));
    memcpy(target->_data_points, buffer + sizeof(Data), target->_size * sizeof(float));
    for(int i=0;i<target->_size; i++)
    {
        printf("After target Data Points[%d]: %f\n", i, target->_data_points[i]);
    }
    _memory_command.data = "";
}


void MemoryManagement::writeMemory(Data *input, char *buffer)
{   
    int size_of_data = sizeof(_test_data);
    int data_point_size = sizeof(float) * input->_size;
    memcpy(buffer, input, size_of_data);
    memcpy(buffer + size_of_data, input->_data_points, data_point_size);
    _memory_command.data = "";
}


void MemoryManagement::deleteMemory()
{
    ROS_INFO("%s Deleted Memory From Buffer\n", MEMORY_MANAGEMENT_LOG_ZONE);
    delete _memory_buffer;
    delete _test_data_for_reading._data_points;
    _memory_buffer_is_removed = true;
    _memory_command.data = "";
}



int main(int argc, char *argv[])
{
    ros::init(argc, argv, "memory_management_node");
    ros::NodeHandle node_handle("~");
    ros::Rate rate(1);

    MemoryManagement memory_management = MemoryManagement(node_handle);
    memory_management.prepareTestData();
    memory_management.writeMemory(&memory_management._test_data, memory_management._memory_buffer);
    memory_management.readMemory(&memory_management._test_data_for_reading, memory_management._memory_buffer);

    ROS_INFO("%s Memory Management", MEMORY_MANAGEMENT_LOG_ZONE);
    ROS_INFO("%s For readMemory Function use the rostopic pub /memory_management topic with 'read' command.", MEMORY_MANAGEMENT_LOG_ZONE);
    while(ros::ok())
    {
        // ROS_INFO("%d Test2:", memory_management._memory_buffer_is_removed);
        if(memory_management._memory_buffer_is_removed == false)
        {
            if(memory_management._memory_command.data == "read")
            {
                memory_management.readMemory(&memory_management._test_data_for_reading, memory_management._memory_buffer);
            }
            else if(memory_management._memory_command.data == "write")
            {
                memory_management.writeMemory(&memory_management._test_data, memory_management._memory_buffer);
            }
            else if(memory_management._memory_command .data== "delete")
            {
                memory_management.deleteMemory();
            }
            else
            {
                ROS_INFO("%s Please publish to /memory_command topic this value: \n", MEMORY_MANAGEMENT_LOG_ZONE);
                ROS_INFO("%s \n For reading memory: 'read' \n For writing memory: 'write' \n For deleting memory: 'delete' \n", MEMORY_MANAGEMENT_LOG_ZONE);
            }   
        }
        else
        {
            if(memory_management._memory_command.data == "prepare")
            {
                memory_management.prepareTestData();
            }
            else
            {
                ROS_INFO("%s \n Memory buffer is removed. Please prepare new Data and write to buffer, publish to /memory_command topic for preparing new data: 'prepare'\n", MEMORY_MANAGEMENT_LOG_ZONE);
            }            
        }
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}