
#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;
  ros::NodeHandle nh;
  
  ros::Publisher pub_redlight = n.advertise<std_msgs::Bool>("red_light", 1000);
  ros::Publisher pub_greenlight = n.advertise<std_msgs::Bool>("green_light",1000);
 
 std_msgs::Int8 test_int;
    std_msgs::String test;
    std::string s;
    
    bool msg_robot_picking_mode;
    msg_robot_picking_mode=false; //initial value
    std_msgs::Bool msg_redlight;
    
    bool msg_robot_collaborative_mode;
    msg_robot_collaborative_mode=false; //initial value
    std_msgs::Bool msg_greenlight;
    
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
   
    
ros::NodeHandle nh;

nh.getParam("/robot_collaborative_mode", msg_robot_collaborative_mode); //gets value from parameter server
nh.getParam("/robot_picking_mode", msg_robot_picking_mode);			

if (msg_robot_collaborative_mode==true)
{
	msg_greenlight.data = true;
	pub_greenlight.publish(msg_greenlight);   //publish to topic
// ROS_INFO("Collaborative Mode ON");
}

if (msg_robot_collaborative_mode==false)
{
	msg_greenlight.data = false;
	pub_greenlight.publish(msg_greenlight);
//	ROS_INFO("Collaborative Mode OFF");
}

if (msg_robot_picking_mode==true)
{ 
	msg_redlight.data = true;
	pub_redlight.publish(msg_redlight);
//	ROS_INFO("Robot picking MODE ON");
}

if (msg_robot_picking_mode==false)
{
	msg_redlight.data = false;
	pub_redlight.publish(msg_redlight);
//	ROS_INFO(" Robot picking MODE off");
}



    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
// %EndTag(FULLTEXT)%

//"Felkod"
//	ROS_INFO("TEST=====:====== ");
//	ROS_INFO("TEST: %s", robot_picking_mode.c_str());
//ROS_INFO("TEST=====:====== %s", robot_picking_mode.c_str());

//ROS_INFO("TEST=====:====== %s", s.c_str());

   //nh.getParam(const std::string &"/robot_picking_mode" bool &msg_redlight);
   //nh.getParam("/robot_collaboration_mode", msg_redlight);
   
   //nh.getParam("/robot_picking_mode", test);
//if (robot_picking_mode.data == "skit")
//{
	//msg_redlight.data = false;
	//pub_redlight.publish(msg_redlight);
//}

 //ROS_INFO("Hej resultat: %s", s.c_str());
