/**
 * file: Driver.hpp
 * @brief Defines the class Driver
 *
 */

#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <string>
#include <vector>
#include "Vehicle.hpp"
#include <algorithm>

class Vehicle;

class Driver {
private:
	static int nextId;

	const int id;
	std::string name;
	std::vector<std::string> licenses;
	Vehicle* assignedVehicle;
public:

	Driver(const std::string& name, const std::vector<std::string>& licenses) : id(++nextId), name(name), licenses(licenses), assignedVehicle(nullptr) {};
	int getId() const {
		return id;
	}
	std::string getName() const {
		return name;
	}
	void setName(const std::string& name) {
		this->name = name;
	}
	const std::vector<std::string>& getLicenses() const {
		return this->licenses;
	}
	void addNewLicense(const std::string& newLicense) {
		licenses.push_back(newLicense);
	}
	void removeLicense(const std::string& licenseToRemove);
	void lendVehicle(Vehicle* vehicleToLend);
};

#endif