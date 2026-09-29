#include <iostream>
#include <string>

class Content{
    private:
    std::string type;
    std::string data;
    void display();
};

class Lesson{
    private:
    Content content;
    std::string title;

    public:
    void addContent(Content& content);
};

class Course{
    private:
    Lesson lesson;
    std::string title;
    std::string description;

    public:
    void addLesson(Lesson& lesson);
};

class Platform{
    private:
    Course course;
    User* user;
    std::string name;

    public:
    void addCourse(Course& course);
};

class User{
    private:
    Course* course;
    std::string name;
    int id;
    
    public:
    void enroll(Course& course);
    void leave(Course& course);
};