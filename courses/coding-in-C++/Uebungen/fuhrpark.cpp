#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

class Motor {
    int leistungPS;
public:
    explicit Motor(int ps) : leistungPS(ps) {}
    int getPS() const { return leistungPS; }
};

class Fahrer {
    std::string name;
public:
    explicit Fahrer(std::string n) : name(std::move(n)) {}
    const std::string& getName() const { return name; }
};

class Auto {
    std::string marke;
    std::unique_ptr<Motor> motor;   // Komposition: Auto besitzt den Motor
    const Fahrer* fahrer = nullptr; // Aggregation: Auto kennt den Fahrer nur

public:
    Auto(std::string m, int ps)
        : marke(std::move(m)), motor(std::make_unique<Motor>(ps)) {}

    void setFahrer(const Fahrer* f) { fahrer = f; }

    const std::string& getMarke() const { return marke; }
    int getPS() const { return motor->getPS(); }
    std::string getFahrerName() const {
        if (fahrer == nullptr) return "keiner";
        return fahrer->getName();
    }
};

int main() {
    // Fahrer leben eigenständig und MÜSSEN die Autos überleben
    Fahrer anna("Anna");
    Fahrer ben("Ben");

    std::vector<std::unique_ptr<Auto>> fuhrpark;
    fuhrpark.push_back(std::make_unique<Auto>("BMW", 200));
    
}
