#include <iostream>
#include <cmath>

class Shape{
private:

public:
    virtual double area()const {return 0.0;}
    virtual ~Shape() {};
};

class Rectangle : public Shape{
private:
    double a;
    double b;
public:
    Rectangle(double a, double b) : a(a), b(b) {};
    ~Rectangle() = default;
    double area() const override{
        return a*b;
    }
};

class Circle : public Shape{
private:
    double r;
    const double pi=3.14;
public:
    Circle(double r) : r(r){};
    ~Circle() = default;
    double area() const override{
        return pi*r*r;
    }
};

int main(){
    Circle c1(1);
    Rectangle r1(2,2);
    Circle c2(4);
    Rectangle r2(8,8);
    Shape* shapes[4]{&c1, &c2, &r1, &r2};
    for(int i=0;i<4;i++){
        std::cout<<shapes[i]->area()<<std::endl;
    }
}