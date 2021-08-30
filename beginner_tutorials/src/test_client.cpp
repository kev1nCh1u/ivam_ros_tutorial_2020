#include "ros/ros.h"
#include "beginner_tutorials/testMsg.h"
#include "beginner_tutorials/testSrv.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_client");
  if (argc != 4)
  {
    ROS_INFO("usage: add_three_ints_client X Y Z");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::testSrv>("test_server_");
  beginner_tutorials::testSrv srv;
  srv.request.TestMsg.a = atoll(argv[1]);
  srv.request.TestMsg.b = atoll(argv[2]);
  srv.request.TestMsg.c = atoll(argv[3]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service test_server");
    return 1;
  }

  return 0;
}
