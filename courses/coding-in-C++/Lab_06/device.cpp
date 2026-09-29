#include "device.hpp"
#include <iostream>

Device::Device(std::string deviceName, std::string deviceType, bool powerStatus)
        : deviceName(deviceName), deviceType(deviceType), powerStatus(powerStatus) {}

Device::~Device() = default;

void Device::turn_off(){
    powerStatus = false;
}
void Device::turn_on(){
    powerStatus = true;
}
void Device::print_info(){
    std::cout<<"Name:"<<deviceName<<std::endl;
    std::cout<<"Type:"<<deviceType<<std::endl;
    std::cout<<"Powerstatus:"<<std::boolalpha<<powerStatus<<std::endl;
}
