#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const ros::MessageEvent<std_msgs::String const>& event)
{
  const std::string& publisher_name = event.getPublisherName();
  const ros::M_string& header = event.getConnectionHeader();
  ros::Time receipt_time = event.getReceiptTime();

  const std_msgs::String::ConstPtr &msg = event.getMessage();

  std::cout << "Header:\n";
  for (auto &kv : header)
  {
    std::cout << "  " << kv.first << " has value " << kv.second << std::endl;
  }

  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
