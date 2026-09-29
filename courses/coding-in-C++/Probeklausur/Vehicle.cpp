#include "Vehicle.hpp"
#include <string>
#include <vector>
#include <iostream>

Driver* Vehicle::getactiveDriver()const{
	return activeDriver;
}

void Combustion::printInfo()const{
	std::cout << "Type"<<"Combustion" << std::endl;
	std::cout << "Brand"<<producer<< std::endl;
	std::cout << "Consumption"<< consumption << std::endl;
	std::cout << "Available"<<std::boolalpha<<available<< std::endl;
	std::cout << "Needed License"<<neededLicense << std::endl;
	std::cout << "Assigned Driver"<<activeDriver->getName() << std::endl;
}

void Electric::printInfo()const{
	std::cout << "Type" << "Electric" << std::endl;
	std::cout << "Brand" << producer<< std::endl;
	std::cout << "Capacity" << capacity << std::endl;
	std::cout << "Available" << std::boolalpha << available << std::endl;
	std::cout << "Needed License" << neededLicense << std::endl;
	std::cout << "Assigned Driver" <<activeDriver->getName() << std::endl;
}

bool Vehicle::rentCar(Driver* chosenDriver){
	if(available){
		if(activeDriver==nullptr){
		for(const std::string license : chosenDriver->getdriverLicenses()){
			if(neededLicense==license){
				activeDriver=chosenDriver;
				return 1;
			}
			}
	}
	}
	return 0;
}
