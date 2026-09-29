#include "bib.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


bool Member::checkAccess(Media* chosenMedia){
    if(chosenMedia->getActiveCustomer() == nullptr){
        if(!activeRent){
            for(std::string access : accessRights){
                if(chosenMedia->getAccess() == access){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void Member::rentMedia(Media* chosenMedia){
    if(checkAccess(chosenMedia)){
        chosenMedia->setActiveCustomer(this);
    }
}

void EBook::printInfo() const{
    std::cout<<std::left<<std::setw(20)<<"Type:"<<"E-Book"<<std::endl;
    std::cout<<std::setw(20)<<"Title:"<<titel<<std::endl;
    std::cout<<std::setw(20)<<"File Size:"<<size<<std::endl;
    std::cout<<std::setw(20)<<"Available:"<<std::boolalpha<<status<<std::endl;
    std::cout<<std::setw(20)<<"Required Access::"<<access<<std::endl;
    std::cout<<std::setw(20)<<"Borrowed By:"<<activeCustomer<<std::endl;

}

void Hearbook::printInfo() const{
    std::cout<<std::left<<std::setw(20)<<"Type:"<<"Audiobook"<<std::endl;
    std::cout<<std::setw(20)<<"Title:"<<titel<<std::endl;
    std::cout<<std::setw(20)<<"Duration:"<<time<<std::endl;
    std::cout<<std::setw(20)<<"Available:"<<std::boolalpha<<status<<std::endl;
    std::cout<<std::setw(20)<<"Required Access::"<<access<<std::endl;
    std::cout<<std::setw(20)<<"Borrowed By:"<<activeCustomer<<std::endl;

}


