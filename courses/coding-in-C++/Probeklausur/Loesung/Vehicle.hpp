/**
 * file: Vehicle.hpp
 * @brief Defines the class Vehicle
 *
 */

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include "Driver.hpp"

class Driver;

class Vehicle {
private:
	static int nextId;
	int id;
	std::string brand;
	double mileage;
	std::string neededLicense;
	bool availability; // true when available
	Driver *assignedDriver;

public:
	Vehicle(const std::string& brand, double mileage, const std::string& neededLicense) : id(++nextId), brand(brand), mileage(mileage), neededLicense(neededLicense), availability(true), assignedDriver(nullptr) {};
	bool isAvailable() const {
		return availability;
	}
	void lendVehicle() {
		availability = false;
	}
	const std::string& getNeededLicense() const {
		return neededLicense;
	}
	const std::string& getBrand() const {
		return brand;
	}
	double getMileage() const {
		return mileage;
	}
	Driver* getAssignedDriver() const{
		return assignedDriver;
	}
	void assignDriver(Driver* driver) {
		this->assignedDriver = driver;
	}
	virtual void printInfo() const = 0;
	virtual ~Vehicle() = default;
};

class Pkw : public Vehicle {
private:
	double consumption;
public:
	Pkw(const std::string& brand, double mileage, const std::string& neededLicense, double consumption) : Vehicle(brand, mileage, neededLicense), consumption(consumption) {};
	double getConsumption() const {
		return consumption;
	}
	void printInfo() const override;
};

class Electro : public Vehicle {
private:
	double capacity;
public:
	Electro(const std::string& brand, double mileage, const std::string& neededLicense, double capacity) : Vehicle(brand, mileage, neededLicense), capacity(capacity) {};
	double getCapacity() const {
		return capacity;
	}
	void printInfo() const override;
};

#endif