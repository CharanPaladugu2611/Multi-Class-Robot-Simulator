#include "aerial_robot.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "mobile_robot.h"
#include "sensor.h"

/**
 * @brief The robot takes off to reach the specified altitude.
 * 
 * @param altitude The desired altitude for take-off.
 */

void RWA2::AerialRobot::take_off(double altitude){
    if (!is_flying_) {

        if(has_wings_){
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(altitude/3.0)));
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(altitude/1.5)));

        }       

        altitude_ = altitude;
        is_flying_ = true;
        std::cout << "take off complete.\n";
    }
}//take_off

/**
 * @brief Land the robot.
 */
void RWA2::AerialRobot::land() {
    if (is_flying_) {
   
        if(has_wings_){
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(altitude_/4.0)));
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(altitude_/2.0)));

        }      
        
        altitude_ = 0.0;
        is_flying_ = false;
        std::cout << "robot landed.\n";
    }

}//land

/**
 * @brief Overwright function: Rotate the robot by a specified angle.
 * 
 * @param angle The angle by which to rotate the robot.
 */
void RWA2::AerialRobot::rotate(double angle) {
    std::cout << "AquaticRobot::" << model_ << " rotated " << angle << " degrees.\n";
}//rotate


/**
 * @brief print the status of the robot
 * 
 */

void RWA2::AerialRobot::print_status() {
    MobileRobot::print_status();
    std::cout << "Does robot have wings? : " << (has_wings_ ? "Yes" : "No") << "\n";
    std::cout << "Robot currently at: " << altitude_ << " meters\n";
    std::cout << "Is robot flying? : " << (is_flying_ ? "Yes" : "No") << "\n";
}//print_status

/**
 * @brief Overwrite function: move the robot
 * 
 * @param distance 
 * @param angle 
 */

void RWA2::AerialRobot::move(double distance, double angle) {

    if (battery_.get_current_charge() < 4*static_cast<int>(distance)) {
        battery_.start_charging();
    }

    //read_data(5);
    take_off(distance / 2);
    rotate(angle);
    land();
    std::cout << model_ << "reached an altitude of " << distance << " meters and then landed.\n";
    print_status();
}//move

