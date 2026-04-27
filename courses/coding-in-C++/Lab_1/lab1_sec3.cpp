#include <iostream>
#include <cstdint>
#include <limits>

namespace validation
{
    bool isadult(std::uint8_t age){
        return age>=18;
    }

    bool isSenior(std::uint8_t age){
        return age>=65;
    }
}

int main(){
    int alter;
    std::cout<<"Bitte Alter eingeben:"<<std::endl;
    while(true){
        if (!(std::cin >> alter))
        {
            std::cout << "Ungueltige Eingabe. Versuche nochmal:" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
            break;
        }

        
    }
    if(validation::isSenior(alter)){
        std::cout<<"Senior"<<std::endl;
    }
    else if(validation::isadult(alter)){
        std::cout<<"Erwachsen"<<std::endl;
    }
    else{
        std::cout<<"Kind"<<std::endl;
    }
}