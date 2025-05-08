#include "legged_robot.h"
#include <iostream>
#include <cmath>
#include "mobile_robot.h"

/**
 * @brief Kick action
 * 
 */
void RWA2::LeggedRobot::kick() {
    std::cout << model_ << "kicks with a strength of" << leg_strength_ << "\n";
}//kick

/**
 * @brief jump action
 * 
 * @param amount 
 */
void RWA2::LeggedRobot::jump(double amount) {
    std::cout << model_ << "jumps at a height of" << (amount/100) * leg_strength_ << " cm above the ground" << "\n";
}//jump

/**
 * @brief rotate the robot
 * 
 * @param angle 
 */
void RWA2::LeggedRobot::rotate(double angle) {
    MobileRobot::rotate(angle);
    std::cout << "LeggedRobot::" << model_ << " rotated " << angle << " degrees." << "\n";
}//rotate

/**
 * @brief print the status of the robot
 * 
 */
void RWA2::LeggedRobot::print_status() {
    MobileRobot::print_status();
    std::cout << "Height of the robot: " << height_ << " meters" << std::endl;
    std::cout << "Leg Strength is: " << leg_strength_ << std::endl;
    std::cout << "Robot has: " << number_of_legs_ << "legs \n";
}//print_status

/**
 * @brief move the robot
 * 
 * @param distance 
 * @param angle 
 */
void RWA2::LeggedRobot::move(double distance, double angle) {

    if (battery_.get_current_charge() < 4*static_cast<int>(height_*100)) {
        battery_.start_charging();
    }

    //read_data(5);
    rotate(angle);
    jump(distance / 2);
    kick();
    print_status();

}//move

