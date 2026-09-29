#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <vector>

class Student{
    private:
    int mtrNummer;
    std::string name;

    public:
    Student(int mtrNummer, std::string name) : mtrNummer(mtrNummer), name(name){}
    ~Student() {};
    std::string getName()const;
    int getMtrNummer()const;
};

class Seminar{
    private:
    static int nextNummer;
    std::vector<Student> teilnehmerListe;
    int seminarNummer;

    public:
    Seminar(std::vector<Student> teilnehmerListe) : teilnehmerListe(teilnehmerListe){
        seminarNummer = nextNummer;
        nextNummer++;
    }
    ~Seminar() {};
    void studentAnmelden(Student s);
    void teilnehmerListeAusgeben();
    int anzahlTeinehmer();


};

#endif