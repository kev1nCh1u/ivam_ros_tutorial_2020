#include "ros/ros.h"
#include "beginner_tutorials/testMsg.h"
#include "beginner_tutorials/testSrv.h"


bool add(beginner_tutorials::testSrv::Request  &req,
         beginner_tutorials::testSrv::Response &res)
{
  res.sum = req.TestMsg.a + req.TestMsg.b + req.TestMsg.c;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_server"); //初始化node
  ros::NodeHandle n; // node handler

  ros::ServiceServer service = n.advertiseService("test_server_", add); //定義service server以及callback function
  ROS_INFO("Ready to add three ints.");
  ros::spin(); //持續運行此node

  return 0;
}
