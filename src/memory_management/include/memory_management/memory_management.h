#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#define MEMORY_MANAGEMENT_LOG_ZONE " [ Memory Management ] "

#include <ros/ros.h>
#include <std_msgs/String.h>

class Data
{
    public:
        int _size;
        char _items[512];
        float *_data_points;
};


class MemoryManagement
{
    private:
        ros::NodeHandle &nh_;

    public:
        /**
         * @brief MemoryManagement Constructor: Defining ros_node and ros_topic
         * @param ros NoneHandle pointer
         * @return None
        */
        MemoryManagement(ros::NodeHandle&);
        ros::Subscriber _memory_command_subscriber;
        
        Data _test_data, _test_data_for_reading;
        char * _memory_buffer;
        bool _memory_buffer_is_removed = false;
        std_msgs::String _memory_command;
        
        /**
         * @brief '/memory_command' topic Callback functions with std_msgs::String type.'
         * @param ConstPtr std_msgs::String::ConstPtr
         * @return None
         */
        void memoryCommandCallback(const std_msgs::String::ConstPtr&);
        
        /**
         * @brief Preparing test data for reading-writing to memory.
         * @param None
         * @return None
        */
        void prepareTestData(void);

        /**
         * @brief Reading data with using memory buffer from Data type object.
         * @param Data type object 
         * @param char type pointer 
         * @return None
        */
        void readMemory(Data *, char *);

        /**
         * @brief Writing data to Data type object with using memory buffer.
         * @param Data type object
         * @param char type pointer
         * @return None 
        */
        void writeMemory(Data *, char *);

        /**
         * @brief Deleting memory from Data type object and memory buffer.
         * @param None
         * @return None
        */
        void deleteMemory(void);

};






#endif