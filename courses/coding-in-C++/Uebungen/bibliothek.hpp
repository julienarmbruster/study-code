#ifndef BIBLIOTHEK_HPP
#define BIBLIOTHEK_HPP

#include <string>
#include <vector>
#include <iostream>

class Bibliothek{
    private:
    std::vector<std::string> buchtitel;

    public:
    Bibliothek(std::vector<std::string> buchtitel);
    ~Bibliothek();
    void buchHinzufuegen(std::string titel);
    void buecherAusgeben() const;
    bool sucheTitel(std::string searchtitel);
};

#endif