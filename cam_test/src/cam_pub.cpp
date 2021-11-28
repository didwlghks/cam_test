#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <my_msgs/CameraData.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "pub_node");
    ros::NodeHandle nh;

    ros::Publisher cam_pub = nh.advertise<my_msgs::CameraData>("/camera/topic",10);
    ros::Rate loop_rate(1);
    my_msgs::CameraData cam_data;


    while(ros::ok()){
        cam_data.p_x = 50;
        cam_data.p_size = 70;
        cam_pub.publish(cam_data);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
