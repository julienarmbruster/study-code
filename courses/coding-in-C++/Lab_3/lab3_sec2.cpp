#include <iostream>
#include <string>

class User
{
    protected:
    std::string name;
    int id;

    public:

    User(std::string name, int id) : name(name), id(id){

    }

    void printInfo(){
        std::cout << "ID: " << id << '\n';
        std::cout << "Name: " << name << '\n';
    }
};

class Student : public User
{
    private:
    int mtrNr;
}

class Instructor : public User
{
    private:
    int age;

}