#ifndef BIB_HPP
#define BIB_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Member;
class Media;

int Media::nextid=0;


class Media{
    protected:
    static int nextid;
    const int id;
    std::string titel;
    bool status;
    std::string access;
    Member* activeCustomer;

    public:
    Media(std::string titel, std::string access) : id(++nextid), titel(titel), status(true), access(access), activeCustomer(nullptr){}
    virtual ~Media() {}
    virtual void printInfo() const = 0;
    Member* getActiveCustomer(){
        return this->activeCustomer;
    }
    std::string getAccess(){
        return access;
    }
    void setActiveCustomer(Member* newCustomer){
        activeCustomer = newCustomer;
    }
};

class EBook: public Media{
    private:
    double size;

    public:
    EBook(std::string titel, std::string access, double size) : Media(titel, access), size(size) {}
    void printInfo() const override;
    
};

class Hearbook: public Media{
    private:
    double time;

    public:
    Hearbook(std::string titel, std::string access, double time) : Media(titel, access), time(time) {}
    void printInfo() const override;
   
};

class Member{
    private:
    static int nextid;
    const int id;
    std::vector<std::string> accessRights;
    bool activeRent;

    public:
    void addRights(std::string addedRight){
        accessRights.push_back(addedRight);
    }
    void deleteRights(std::string deletedRight){
        std::replace(accessRights.begin(), accessRights.end(), deletedRight, std::string("empty"));
    }
    bool checkAccess(Media* chosenMedia);
    void rentMedia(Media* chosenMedia);
};
template<typename V,typename E>
class Administration{
    private:
    std::vector<std::unique_ptr<V>> Members;
    std::vector<std::unique_ptr<E>> MediaItems;
    public:
    void addMember(std::unique_ptr<V> addedElement){
        Members.push_back(std::move(addedElement));
    }
    void addMedia(std::unique_ptr<E> addedElement){
        MediaItems.push_back(std::move(addedElement));
    }

};

#endif