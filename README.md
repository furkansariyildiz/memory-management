# Memory Management

### To Build

+ sudo rm -r build && sudo rm -r devel

+ catkin_make

### To Source

+ source devel/setup.bash

### To Run

+ With roslaunch: roslaunch memory_management memory_management.launch

+ With rosrun: rosrun memory_management memory_management_node

```
After running the code, you should publish to '/motor_command' topic with std_msgs::String type.

Data should be like this for;
+ reading memory: 'read'
+ writing memory: 'write
+ deleting memory: 'delete'
+ preparing test data: 'prepare'
```

+ You can follow instruction from ROS terminal.
