#include "Driver.hpp"
#include <string>
#include <vector>

void Driver::addLicense(std::string newLicense) {
	driverLicenses.push_back(newLicense);
}

void Driver::deleteLicense(std::string deletedLicense) {
	for (int i = 0; i < driverLicenses.size(); i++) {
		if(driverLicenses[i]==deletedLicense){
			driverLicenses[i] = "0";
		}
	}
}

const std::vector<std::string>& Driver::getdriverLicenses()const{
		return driverLicenses;
}

const std::string& Driver::getName()const{
	return name;
}