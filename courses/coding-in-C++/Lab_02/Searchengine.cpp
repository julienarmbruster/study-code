#include <iostream>
#include <string>
#include <vector>
#include "Searchengine.hpp"

std::vector<Resource> Searchengine::search(const Query& q){
    for (const Resource& r : web){
        if(r.getInfo().find(q.getTextinput()) != std::string::npos){
            results.push_back(r);
        }
    }
    return results;
}

void Searchengine::printResults(std::vector<Resource> results){
    for(const Resource& r : results){
        std::cout<<"Addresse:"<<r.getAddress()<<std::endl;
        std::cout<<"Info:"<<r.getInfo()<<std::endl;
        std::cout<<"Ranking:"<<r.getRanking()<<std::endl;
        
}
    }
    
//std::vector<Resource> Searchengine::sortResources(std::vector<Resource> unsortResource){}

bool Query::validQuery(int maxResults)const{
    if(maxResults>0){
        return 1;
    }
    else{
        return 0;
    }
}

std::string Query::getTextinput()const{
    return textinput;
}

Query::Query(const std::string textinput, int maxResults)
    : textinput(textinput), maxResults(maxResults) {}


Resource::Resource(const std::string& address, const std::string& info, double ranking)
    : address(address), info(info), ranking(ranking) {}

std::string Resource::getAddress()const{
    return address;
}

std::string Resource::getInfo()const{
    return info;
}

double Resource::getRanking()const{
    return ranking;
}

int main(){
    Resource r1("www.hallo.de", "Hallo", 0.9);
    Searchengine s;
    s.addResource(r1);
    Query q1("Test",10);
    s.printResults(s.search(q1));
    return 0;
}