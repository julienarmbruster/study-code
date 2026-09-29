#include <iostream>
#include <string>

static constexpr int max_temperature = 100;
static constexpr int min_temperature = 0;
static constexpr int max_sugar = 50;


class Drinkbuilder
{
    private:
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;
    
    public:

    Drinkbuilder() : name(""), sugar(0), temperature(0), withMilk(false) {}
    Drinkbuilder(std::string name, int sugar, int tempereture, bool withmilk){}
    Drinkbuilder& setName(const std::string& name){
        this->name = name;
        return *this;
    }
    Drinkbuilder& setSugar(int sugar){
        this->sugar = sugar;
        return *this;
    }
    Drinkbuilder& setTemperature(int temperature){
        this->temperature = temperature;
        return *this;
    }
    Drinkbuilder& setWithMilk(bool withMilk){
        this->withMilk = withMilk;
        return *this;
    }
    void print(){
        std::cout<<"Name:"<<name<<std::endl;
        std::cout<<"Sugar:"<<sugar<<std::endl;
        std::cout<<"Temperature:"<<temperature<<std::endl;
        std::cout<<std::boolalpha<<"Withmilk:"<<withMilk<<std::endl;
    }

    bool isValid() const{
        if(temperature>=max_temperature){
            return 0;
        }
        else if(temperature<=min_temperature){
            return 0;
        }
        else if(sugar>max_sugar||sugar<0){
            return 0;
        }
        else{
            return 1;
        }
    }
};

int main(){
    Drinkbuilder builder;
    builder.setName("Espresso").setSugar(20).setTemperature(90).setWithMilk(false);
    /*
    Drinkbuilder builder;
    builder.setName("Espresso");
    builder.setSugar(20);
    builder.setTemperature(90);
    builder.setWithMilk(false);
    
    */
    
    if(builder.isValid()){
        builder.print();
    }
    else{
        std::cout<<"invalid"<<std::endl;
    }
    

}