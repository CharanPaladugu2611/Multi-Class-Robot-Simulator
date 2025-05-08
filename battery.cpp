#include "battery.h"
#include <thread>
#include <chrono>
    



void RWA2::Battery::start_charging() {

    if (!is_charging_){
        
        std::cout << model_<< " battery is charging.\n";

        if (model_ == "Li-ion") {
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>((100.0 - current_charge_) / 7.0)));
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>((100.0 - current_charge_) / 3.5)));
        }

        current_charge_ = 100;
        is_charging_ = false;

        stop_charging();
    } else{
        std::cerr << "Battery is already charging.\n";
    }
}//start_charging


/**
 * @brief Discharging the battery
 * 
 * @param amount 
 */
void RWA2::Battery::discharge(double amount) {

    current_charge_ = current_charge_ - static_cast<int>(amount);

}//discharge

