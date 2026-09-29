#ifndef DRIVER_HPP
#define DRIVER_HPP
#include <string>
#include <vector>

class Driver {
private:
	const int driverID;
	std::string name;
	std::vector<std::string> driverLicenses;

public:
	Driver(const int driverID, std::string name, std::vector<std::string> driverLicenses)
		: driverID(driverID), name(name), driverLicenses(driverLicenses) {
	}
	void addLicense(std::string newLicense);
	void deleteLicense(std::string deletedLicense);
	const std::vector<std::string>& getdriverLicenses()const;
	const std::string& getName()const;
};

#endif