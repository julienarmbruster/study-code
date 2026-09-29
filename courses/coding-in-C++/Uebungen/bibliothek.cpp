#include "bibliothek.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void Bibliothek::buchHinzufuegen(std::string titel){
    buchtitel.push_back(titel);
}

void Bibliothek::buecherAusgeben() const{
    for(std::string titel : buchtitel){
        std::cout<<std::left<<std::setw(20)<<titel<<"."<<std::endl;
    }
}

bool Bibliothek::sucheTitel(std::string searchtitel){
    for(std::string titel : buchtitel){
        if(searchtitel==titel){
            std::cout<<"Suche nach: "<<searchtitel<<" gefunden!"<<std::endl;
            return true;
        }
    }
    std::cout<<"Suche nach: "<<searchtitel<<" nicht gefunden!"<<std::endl;
    return false;
}

Bibliothek::Bibliothek(std::vector<std::string> buchtitel) : buchtitel(buchtitel){}

Bibliothek::~Bibliothek(){}

int main(){
    std::vector<std::string> Buecher = {"eins", "zwei", "drei", "vier"};
    Bibliothek bib1(Buecher);
    bib1.buchHinzufuegen("Harry");
    bib1.buecherAusgeben();
    bib1.sucheTitel("Harr");
}