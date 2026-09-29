#include "student.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

int Seminar::nextNummer = 0;


void Seminar::studentAnmelden(Student s){
    teilnehmerListe.push_back(s);
}

std::string Student::getName()const{
    return this->name;
}

int Student::getMtrNummer()const{
    return this->mtrNummer;
}


void Seminar::teilnehmerListeAusgeben(){
    std::cout<<"Anzahl: "<<teilnehmerListe.size()<<std::endl;
    for(const Student& s : teilnehmerListe){
        std::cout<<std::left<<std::setw(20)<<s.getName()<<s.getMtrNummer()<<std::endl;
    }

}

int main(){
    Student s1(0001, "Bennet");
    Student s2(0002, "Marc");
    std::vector<Student> se1Teilnehmer= {s1};
    Seminar se1(se1Teilnehmer);
    se1.teilnehmerListeAusgeben();
    se1.studentAnmelden(s2);
    se1.teilnehmerListeAusgeben();
    Seminar se2(se1Teilnehmer);
}
