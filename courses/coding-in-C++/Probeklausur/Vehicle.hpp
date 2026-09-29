#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>
#include "Driver.hpp"

class Vehicle {
protected:
	int vehicleID;
	std::string producer;
	bool available;
	std::string neededLicense;
	Driver* activeDriver;

public:
	Vehicle(int vehicleID, std::string producer, bool available, std::string neededLicense)
		: vehicleID(vehicleID), producer(producer), available(available), neededLicense(neededLicense), activeDriver(nullptr) {
	}
	virtual ~Vehicle() = default;
	virtual void printInfo()const = 0;
	bool rentCar(Driver*);
	Driver* getactiveDriver()const;
};

class Combustion : public Vehicle {
private:
private:
	double consumption;

public:
	virtual void printInfo()const override;
};

class Electric : public Vehicle {
private:
	double capacity;

public:
	virtual void printInfo()const override;
};

#endif