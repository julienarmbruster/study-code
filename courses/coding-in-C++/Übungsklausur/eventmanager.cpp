#include "eventmanager.hpp"
#include<string>
#include<vector>
#include<iostream>
#include<memory>

Event::Event(std::string title, int maxCapacity, double basicPrice, std::vector<Member*> memberList) 
 : title(title), maxCapacity(maxCapacity), basicPrice(basicPrice), memberlist(memberList)
 {
    id = nextid;
    nextid++;
}
 

void Concert::printInfo() const{
    std::cout << "Infos Concert" << std::endl;
}

void Workshop::printInfo() const{
    std::cout << "Infos Workshop" << std::endl;
}

int Event::getID() const{
    return this-> id;
}

Eventmanager::Eventmanager(std::vector<std::unique_ptr<Event>>& events, std::vector<std::unique_ptr<Member>>& members)
    : events(events), members(members){}

bool Member::bookEvent(Event* bookedEvent){
    for(int id : activeBookingsID){
        if(id==bookedEvent->getID()){
            return false;
        }
    }
}
