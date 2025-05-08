#include <memory>
#include <iostream>
#include "mobile_robot.h"
#include "aquatic_robot.h"
#include "aerial_robot.h"
#include "wheeled_robot.h"
#include "legged_robot.h" 


int main()
{	/**
 * @brief Testing out different robots.
 * 
 */
//AerialRobot(double x, double y, 
// double orientation, 
// std::string model, 
// std::string battery_model, 

// int current_charge, 
// bool is_charging, 
// bool has_wings, 
// double speed = 0.0, 
// double altitude = 0.0, 
// bool is_flying = false)


	auto neptunes_eye = std::make_unique<RWA2::AquaticRobot>(0.0, 0.0, 0.0, "SoFi", "Li-ion", 100, false, true, 0.0, 0.0, false);
	neptunes_eye->print_status();


// AerialRobot(double x, double y, 
// double orientation, 
// std::string model, 
// std::string battery_model, 
// int current_charge, 
// bool is_charging, 
// bool has_wings, 
// double speed = 0.0, 
// double altitude = 0.0, 
// bool is_flying = false)

	auto mechbirdie = std::make_unique<RWA2::AerialRobot>(0.0, 0.0, 0.0, "Erle-Plane", "Li-ion", 100, false, true, 0.0, 0.0, false);
	mechbirdie->print_status();
	

}


