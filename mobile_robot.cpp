#include "mobile_robot.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "aquatic_robot.h"


/**
 * @brief rotate the robot
 * 
 * @param angle 
 */

void RWA2::MobileRobot::rotate(double angle) {
    // Add angle to orientation_ if angle is positive or subtract angle from orientation_ if angle is negative.

    if (angle > 0) {
        orientation_ += angle;
    } else {
        orientation_ -= angle;
    }
}//rotate

/**
 * @brief move() is used to move the robot
 * 
 * @param distance 
 * @param angle 
 */
void RWA2::MobileRobot::move(double distance, double angle) {
    position_.first += distance * cos(angle);
    position_.second += distance * sin(angle);
    
}//move


/**
 * @brief print the status of the robot
 * 
 */
void RWA2::MobileRobot::print_status() {

    std::cout << "position: " << position_.first << ", " << position_.second << "\n";
    std::cout << "orientation: " << orientation_ << "\n";
    std::cout << "speed: " << speed_ << "\n";

}//print_status

