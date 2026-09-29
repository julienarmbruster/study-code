/*#include <iostream>

class Inspection{

    public:
    virtual bool inspect() const = 0;
};



class CombustionRule{
    private:

    const double MAX_WEIGHT = 100;
    const double MIN_WEIGHT = 90;
    const double MAX_TEMPERATURE = 40;
    const double MIN_TEMPERATURE = 15;
    const double VISUALEFFECT_BORDER = 1;

    public:

    bool weightCheck(const CombustionEngine& engine) const{
        return engine.weight > MIN_WEIGHT && engine.weight < MAX_WEIGHT;
    }

    bool temperatureCheck(const CombustionEngine& engine) const{
        return engine.temperature > MIN_TEMPERATURE && engine.temperature < MAX_TEMPERATURE;
    }
    bool visualCheck(const CombustionEngine& engine)const{
        return engine.visualeffectStatus > VISUALEFFECT_BORDER;
    }

    

};

class ElectricRule{
    
};

class CombustionEngine : public CombustionRule : Inspection{
    public:
    double temperature;
    double weight;
    double visualeffectStatus;

    CombustionEngine(double temperature, double weight, double visualeffectStatus)
        : temperature(temperature), weight(weight), visualeffectStatus(visualeffectStatus){}
    
    bool inspect() const {
        return weightCheck(*this) && temperatureCheck(*this) && visualCheck(*this);
    }
};



int main(){
    CombustionEngine e1(35,91,1.1);
    if(e1.inspect()){
        std::cout<<"Bestanden"<<std::endl;
    }
}
    */