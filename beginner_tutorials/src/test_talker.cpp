#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include "beginner_tutorials/testMsg.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<beginner_tutorials::testMsg>("chatter", 1000);
    ros::Rate loop_rate(10);
    int count = 0;
    while(ros::ok())
    {
        beginner_tutorials::testMsg msg;
        std::stringstream ss;
        ss<<"hello world"<<count;
        msg.strVal = ss.str();
        ROS_INFO("%s", msg.strVal.c_str());
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
