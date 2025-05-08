#include "sensor.h"
#include <chrono>
#include <thread>
#include <array>
#include <random>

/**
 * @brief Supposed to be in aggregation with the MobileRobot class
 * 
 * @param model, duration
 */
void RWA2::Sensor::read_data(unsigned int duration) {

    std::cout << "Sensor " << model_ << " gathering data for " << duration << " seconds.\n";
    std::this_thread::sleep_for(std::chrono::seconds(duration));

    std::array<double, 50> randArray;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 30.0);

    for (int i = 0; i < 50; ++i) {
        randArray[i] = dis(gen); 
    }

    data_ = randArray;

    std::cout << "Gathered Data:" << std::endl;
    
    for (int i = 0; i < 50; ++i) {
        std::cout << randArray[i] << " ";
    }

}//read_data

