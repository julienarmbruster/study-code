#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

class Device{
private:
    std::string deviceName;
    std::string deviceType;
    bool powerStatus = false;

public:
    Device(std::string deviceName, std::string deviceType, bool powerStatus);
    ~Device();
    void turn_on();
    void turn_off();
    void print_info();
};

#endif