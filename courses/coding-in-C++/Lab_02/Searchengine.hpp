#include <vector>
#include <string>

class Resource{
private:
    std::string address;
    std::string info;
    double ranking;

public:
    std::string getAddress()const;
    std::string getInfo()const;
    double getRanking()const;

    Resource(const std::string& address, const std::string& info, double ranking);
};

class Query{
private:
    std::string textinput;
    int maxResults;

public:
    bool validQuery(int maxResults)const;
    std::string getTextinput()const;
    Query(const std::string textinput, int maxResults);

};

class Searchengine{
private:
    std::vector<Resource> web;
    std::vector<Resource> results;
    std::vector<Resource> unsortedResults;

public:
    std::vector<Resource>search(const Query& q);
    std::vector<Resource>sortResources(std::vector<Resource> unsortResource);
    void printResults(std::vector<Resource> results);
    void addResource(const Resource& r) {
        web.push_back(r);
    }

};



