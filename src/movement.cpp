/*Este nodo fue desarrollado para mover el robot*/

#include "ros/ros.h"
#include <stdio.h>
#include "geometry_msgs/Twist.h"

int main (int argc, char** argv)
{
    geometry_msgs::Twist msg;
        msg.linear.x = 0;
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 0;

    int input;


    ros::init (argc, argv, "movement");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 100); //Creación del topic
    //Creación de la variable mensaje e inicialización de variables
   
    ros::Rate loop(1); //Loop de 1Hz

    ROS_INFO ("Presione una tecla para mover el robot (apretar muchas veces aumenta la velocidad):\n"
            "> WASD mueven en las cuatro direcciones.\n"
            "> Q,E rotan el robot.\n"
            "> F detiene todo movimiento.\n" );
  
    while (ros::ok()) 
    {
        input = getchar ();
        switch (input)
        {
            case 'w':
            {
                msg.linear.x += 0.1;
                break;
            }

            case 'a':
            {
                msg.linear.y += 0.1;
                break;
            }

            case 's':
            {
                msg.linear.x -= 0.1;
                break;
            }

            case 'd':
            {
                msg.linear.y -= 0.1;
                break;
            }

            case 'q':
            {
                msg.angular.z += 0.1;
                break;
            }

            case 'e':
            {
                msg.angular.z -= 0.1;
                break;
            }

            case 'f':
            {
                msg.linear.x = 0;
                msg.linear.y = 0;
                msg.linear.z = 0;
                msg.angular.x = 0;
                msg.angular.y = 0;
                msg.angular.z = 0;
                break;
            }

            default:
            {
                break;
            }
    }
    
    pub.publish (msg); //Publico el mensaje
   }
   return 0;
}