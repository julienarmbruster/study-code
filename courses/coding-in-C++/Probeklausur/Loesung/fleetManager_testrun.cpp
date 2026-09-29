/**
 * file: fleetManager_testrun.cpp
 * @brief Contains main() function and various method definitions for class Vehicle and Driver
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Driver.hpp"
#include "Vehicle.hpp"

// initialize static variables of the classes
int Driver::nextId = 0;
int Vehicle::nextId = 0;

void Driver::removeLicense(const std::string& licenseToRemove) {
	auto it = std::find(licenses.begin(), licenses.end(), licenseToRemove);
	// if the correct license is found, erase it
	if (it != licenses.end()) {
		licenses.erase(it);
	}
}

void Driver::lendVehicle(Vehicle* vehicleToLend) {
	// check 1: driver has no car assigned yet
	if (!(this->assignedVehicle == nullptr)) {
		std::cout << "Error: Driver has already a vehicle assigned." << std::endl;
		return;
	}
	// check 2: vehicle is available
	if (vehicleToLend->isAvailable()) {

		// check 3: licenses match
		if (std::find(licenses.begin(), licenses.end(), vehicleToLend->getNeededLicense()) != licenses.end()) {
			// assign vehicle process
			this->assignedVehicle = vehicleToLend;
			vehicleToLend->lendVehicle();
			vehicleToLend->assignDriver(this);
		}
		else {
			std::cout << "No matching license for this vehicle" << std::endl;
		}
	}
	else {
		std::cout << "Vehicle is currently not available" << std::endl;
	}
}

void Pkw::printInfo() const {
	std::cout << std::setw(20) << "Type" << std::setw(20) << "PKW" << '\n';
	std::cout << std::setw(20) << "Brand" << std::setw(20) << this->getBrand() << '\n';
	std::cout << std::setw(20) << "Mileage" << std::setw(20) << this->getMileage() << '\n';
	std::cout << std::setw(20) << "Consumption per 100Km" << std::setw(20) << this->getConsumption() << '\n';
	std::cout << std::setw(20) << "Availability" << std::setw(20) << std::boolalpha << this->isAvailable() << '\n';
	std::cout << std::setw(20) << "Needed license" << std::setw(20) << this->getNeededLicense() << '\n';
	std::cout << std::setw(20) << "Assigned Driver" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getName()) << '\n';
}

void Electro::printInfo() const {
	std::cout << std::setw(20) << "Type" << std::setw(20) << "Elektrofahrzeug" << '\n';
	std::cout << std::setw(20) << "Brand" << std::setw(20) << this->getBrand() << '\n';
	std::cout << std::setw(20) << "Mileage" << std::setw(20) << this->getMileage() << '\n';
	std::cout << std::setw(20) << "Capacity" << std::setw(20) << this->getCapacity() << '\n';
	std::cout << std::setw(20) << "Availability" << std::setw(20) << std::boolalpha << this->isAvailable() << '\n';
	std::cout << std::setw(20) << "Needed license" << std::setw(20) << this->getNeededLicense() << '\n';
	std::cout << std::setw(20) << "Assigned Driver" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getName()) << '\n';
}

int main()
{
	// create objects
	Pkw pkw1("BMW", 333, "B", 6.3);
	Electro elect1("BMW", 444, "B", 75);

	std::vector<std::string> driver1Licenses;
	driver1Licenses.push_back("B");
	driver1Licenses.push_back("C1");

	Driver driver1("Nikki Lauda", driver1Licenses);

	pkw1.printInfo();
	std::cout << "--------------------------------------------------------" << std::endl;

	driver1.lendVehicle(&pkw1);

	pkw1.printInfo();

	driver1.lendVehicle(&elect1);

	std::vector<Vehicle*> fleet;
	fleet.push_back(&pkw1);
	fleet.push_back(&elect1);

	for (auto curVehicle : fleet) {
		std::cout << "--------------------------------------------------------" << std::endl;
		curVehicle->printInfo();
	}
}

// Mit dem Schlüsselwort override in der abgeleiteten Klasse kann sichergestellt werden, dass die korrekte virtuelle Methode überschrieben wird. Das Schlüsselwort wird hinter die Methodensignatur geschrieben.
// Dadurch prüft der Compiler, ob tatsächlich eine virtuelle Methode der Basisklasse mit exakt derselben Signatur existiert und überschrieben wird.
// Falls nicht, meldet der Compiler einen Fehler. Dadurch sinkt das Fehlerrisiko eine falsche Signatur zu verwenden bei virtuellen Methoden.
