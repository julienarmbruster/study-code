#include <iostream>
#include <string>

class Node{
    private:
    std::string* Text;

    public:
    Node(std::string Input){
        Text = new std::string(Input);
    };
    Node(Node& other){
        Text = new std::string(*other.Text);

    };
    ~Node(){
        delete Text;
        Text = nullptr;
    };
    void display(){
        std::cout<<*Text<<std::endl;
    };
};

int main(){
    Node n1("Hallon1");
    Node n2 = n1;
    n1.display();
    n2.display();
    Node n3(n1);
    n3.display();
}