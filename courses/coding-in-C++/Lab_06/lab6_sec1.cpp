#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <memory>

class ConfigLoader{
public:
    void load(std::string filename){
        // throw if filename does not contain the .cfg extension
        if(filename.find(".cfg") == std::string::npos){
            throw std::invalid_argument(".cfg Endung fehlt");
        }
        if(filename.empty()){
            throw std::invalid_argument("Leerer Name");
        }
    }
};

int main(){
    try{
        ConfigLoader loader;
        loader.load("");

    }
    catch(std::exception& Fehler){
        std::cout<<"Fehler:"<<Fehler.what()<<std::endl;
    }
    std::unique_ptr<int> p = std::make_unique<int>(5);
}