#include <iostream>
#include <string>

class Note{
private:
    std::string* text;

public:
    Note(std::string Nachricht)
        : text(new std::string(Nachricht)) {
    }

    Note(const Note& other)
        : text(new std::string(*other.text)) {
    }

    ~Note(){
        delete text;
        text = nullptr;
        std::cout << "Memory released\n";
    }

    void display() {
        std::cout << *text << '\n';
    }

};

int main() {
    Note n1("Hallo aus n1");

    Note n2 = n1;
    Note n3(n1);

    n1.display();
    n2.display();
    n3.display();

    
    return 0;
}