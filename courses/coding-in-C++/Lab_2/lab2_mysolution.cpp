#include <iostream>
#include <string>

class BankAccount{
private:
    std::string owner;
    double balance;

public:
    
    void setOwner(std::string name){
        owner = name;
    }

    std::string getOwner(){
        return owner;
    }
    void deposit(double deposit){
        if(deposit>0){
            balance = balance + deposit;
        }
        
    }
    void withdraw(double withdraw){
        if(balance>withdraw){
            balance = balance - withdraw;
        }
    }
    
    double getBalance() const;

    void getAccountInfo();
    
};

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::getAccountInfo(){
    std::cout << getBalance() << getOwner() << std::endl;
}
    