#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
    //节点初始化
    ros::init(argc, argv, "velocity_publisher");//自定义节点名称即可
    ros::NodeHandle n;


    //创建一个publisher，发布名为/turtle1/cmd_topic的topic，
    //消息类型为geometry_msgs::Twist，队列长度为10
    ros::Publisher turtle_vel_pub/*发布者*/=n.advertise<geometry_msgs::Twist/*发布的数据类型*/>("/turtle1/cmd_vel", 10);
    //    /turtle1/cmd_vel是传输信息的topic


    //设置循环的频率
    ros::Rate loop_rate(10);
    int count = 0;
    while(ros::ok()){
    //初始化geometry_msgs::Twist类型的消息
    geometry_msgs::Twist   vel_msg;//相当于声明一个geometry_msgs::Twist类型的变量
    vel_msg.linear.x=1.0;
    vel_msg.angular.z=1.0;

//发布信息
turtle_vel_pub.publish(vel_msg);
ROS_INFO("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]",vel_msg.linear.x,vel_msg.angular.z);

loop_rate.sleep();

    }




    return 0;
}