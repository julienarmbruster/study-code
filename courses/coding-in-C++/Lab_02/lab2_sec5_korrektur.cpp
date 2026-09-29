#include <iostream>
#include <string>
using namespace std;

class Article {
private:
    string name;//alle paramter private
    double price;
    int stock;
    string category;
    int id;
    
public:
    Article(const string& name, double price, int stock, const string &category, int id) 
        : name(name), price(price), stock(stock), id(id), category(category){
        /*
        this->name = name;//this->
        this->price = price;
        this->stock = stock;
        this->id = id;
        this->category = category;
        */
        
    }

    void setPrice(double price) {
        if(price>0){
            this->price = price;//this->
        }
        else{
            cout<<"Invalid Price"<<endl;
        }
        
    }

    void sell(int amount) {
        this->stock = stock - amount;//überprüfung auf vorzeichen
    }

    void restock(int amount) {
        if(amount>=0){
            stock += amount;
        }
        else{
            cout<<"Amount not valide"<<endl;
        }
    }

    double applyDiscount(double percent) {
        if(percent>=0&&percent<=100){
            price = price - price * percent / 100;
            return price;
        }else{
            cout<<"Percent not valide"<<endl;
            return -1;
        }
        
    }

    double getPrice() const {
        return price;
    }

    bool isAvailable() const {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() const {
        cout << "Article: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(5);
    a.setPrice(150);
    a.applyDiscount(50);

    if (a.isAvailable()) {
        cout << "Article available" << endl;

    a.printInfo();
    }
}