#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP
#include <vector>
#include <string>
#include <memory>

class Event;
class Member;

class Eventmanager{
    private:
    std::vector<std::unique_ptr<Event>> events;
    std::vector<std::unique_ptr<Member>> members;

    public:
    Eventmanager(std::vector<std::unique_ptr<Event>>& events, std::vector<std::unique_ptr<Member>>& members);
    int getBookings() const;
    int getfullEvents() const;
    double getearnedMoney() const;
    Event* getEventbyID(int id);
};

class Event{
    private:
    static int nextid;
    int id;
    std::string title;
    int maxCapacity;
    double basicPrice;
    std::vector<Member*> memberlist;

    public:
    Event(std::string title, int maxCapacity, double basicPrice, std::vector<Member*> memberList);
    ~Event();
    virtual void printInfo() const;
    std::vector<Member*>& getMembers() const;
    int getID() const;
};

class Concert : public Event{
    private:
    std::string artist;

    public:
    void printInfo() const override;
};

class Workshop : public Event{
    private:
    std::string leaderName;
    double duartionHours;

    public:
    void printInfo() const override;
};


class Member{
    private:
    static int nextId;
    int id;
    std::string name;
    std::vector<std::string> interests;
    std::vector<int> activeBookingsID;

    public:
    Member(std::string name);
    int getId() const;
    std::string getName() const;
    void addInterest(std::string newInterest);
    void deleteInterest(std::string deletedInterest);
    bool bookEvent(Event* bookedEvent);
};

#endif
 