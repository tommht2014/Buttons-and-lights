#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Bool.h"

void chatterCallback_stop(const std_msgs::Bool::ConstPtr& msg_stop)
{
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
  
  if (msg_stop->data==true) {
	  ROS_INFO("Go");  
	  ros::NodeHandle nh;
	nh.setParam("/emergency_button",false);
	}
	else{
	ROS_INFO("Stop");
    ros::NodeHandle nh;
	nh.setParam("/emergency_button",true);
	  }
  

}

void chatterCallback_start(const std_msgs::Bool::ConstPtr& msg_start)
{
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
  
  if (msg_start->data==true) {
	  ROS_INFO("Nothing");  
	  ros::NodeHandle nh;
	nh.setParam("/next_robotmovement_button",false);
	}
	else{
	ROS_INFO("Start robot next movement");
    ros::NodeHandle nh;
	nh.setParam("/next_robotmovement_button",true);
	  }
  

}
// %EndTag(CALLBACK)%

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

// %Tag(SUBSCRIBER)%
  ros::Subscriber sub_stop;
  ros::Subscriber sub_start;
  sub_stop= n.subscribe("pushed_stop", 1000, chatterCallback_stop);
  sub_start= n.subscribe("pushed_start", 1000, chatterCallback_start);
// %EndTag(SUBSCRIBER)%

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
// %Tag(SPIN)%
  ros::spin();
// %EndTag(SPIN)%

  return 0;
}
// %EndTag(FULLTEXT)%
