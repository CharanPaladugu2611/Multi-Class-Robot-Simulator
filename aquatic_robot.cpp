#include "aquatic_robot.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "mobile_robot.h"
#include "sensor.h"



/**
 * @brief dive() The robot dives to reach depth.
 * 
 * @param depth 
 */
void RWA2::AquaticRobot::dive(double depth) {
    if (!is_diving_) {

        if (has_fins_){
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(depth/2.0)));
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(depth)));
        }

        depth_ = depth;
        is_diving_ = true;

        std::cout << "dive complete.\n";
    }
    else {
        std::cerr << "AquaticRobot is already diving.\n";
    }
}//dive


/**
 * @brief surface() Action of moving the robot to the surface.
 * 
 */
void RWA2::AquaticRobot::surface() {
    if (is_diving_) {

        if (has_fins_){
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(depth_/2.0)));
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(depth_)));
        }

        is_diving_ = false;
        depth_ = 0.0;

        battery_.start_charging();

        std::cout << "surfacing complete.\n";
    }
    else {
        std::cerr << "AquaticRobot is not currently diving.\n";
    }
}//surface


/**
 * @brief rotate() is used to rotate the robot
 * 
 * @param angle 
 */

void RWA2::AquaticRobot::rotate(double angle) {
    std::cout << "AquaticRobot::" << model_ << " rotated " << angle << " degrees.\n";
}//rotate

/**
 * @brief print_status() is used to print the status of the robot
 * 
 */
void RWA2::AquaticRobot::print_status() {
    MobileRobot::print_status();
    std::cout << "has_fins_: " << (has_fins_ ? "Yes" : "No") << "\n";
    std::cout << "depth_: " << depth_ << " meters\n";
    std::cout << "is_diving: " << (is_diving_ ? "Yes" : "No") << "\n";
}//print_status

/**
 * @brief move(): to move the robot
 * 
 * @param distance 
 * @param angle 
 */
void RWA2::AquaticRobot::move(double distance, double angle) {

    if (battery_.get_current_charge() < 2*static_cast<int>(distance)) {
        battery_.start_charging();
    }
    
    //read_data(5);
    rotate(angle);
    dive(distance / 2);
    surface();
    std::cout << model_ << " reached a depth of " << distance << " meters and then surfaced.\n";
    print_status();

    battery_.discharge(2*static_cast<int>(distance));

}//move
