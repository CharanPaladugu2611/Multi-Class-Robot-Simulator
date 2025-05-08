#include "wheeled_robot.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "mobile_robot.h"
#include "sensor.h"


/**
 * @brief accelerate the robot by amount
 * 
 * @param amount 
 */
void RWA2::WheeledRobot::accelerate(double amount){
    while (speed_ <= desired_speed_) {
        speed_ += amount;
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(0.5)));
    }
    std::cout << model_ << "has reached the desired speed of " << desired_speed_ << "m/s \n";
}//accelerate

/**
* @brief decelerate the robot
* 
* @param amount 
*/

void RWA2::WheeledRobot::decelerate(double amount) {
    while (speed_ >= 0.0) {
        speed_ -= amount;
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(0.5)));
    }
}//decelerate

/**
 * @brief stop the robot
 * 
 */
void RWA2::WheeledRobot::brake() {
    speed_ = 0.0;
}//brake


void RWA2::WheeledRobot::rotate(double angle) {
    std::cout << "WheeledRobot::" << model_ << " rotated by" << angle << "degrees." <<"\n";
}//rotate

/**
 * @brief print the status of the robot
 * 
 */
void RWA2::WheeledRobot::print_status() {
    MobileRobot::print_status();
    std::cout << "Number of Wheels on the robot: " << number_of_wheels_ << "\n";
    std::cout << "Each wheel has dia of: " << wheel_diameter_ << " cm" << "\n";
    std::cout << "Current desired speed: " << desired_speed_ << " m/s" << "\n";
}//print_status

/**
 * @brief move the robot
 * 
 * @param distance 
 * @param angle 
 */
void RWA2::WheeledRobot::move(double distance, double angle) {
    if (battery_.get_current_charge() < static_cast<int>(distance)) {
        battery_.start_charging();
    }
    // read_data(5);
    rotate(angle);
    accelerate(2);
    decelerate(2);
    brake();

    std::cout << model_ << "drove" << distance << "m.\n";
    print_status();
}//move
