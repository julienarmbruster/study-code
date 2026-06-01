#include <iostream>
#include <cmath>

class Shape{

    private:

    public:

    virtual double area() const {return 0.0;}

    
    virtual ~Shape(){};
};

class Circle : public Shape{
    private:
    double rad;
    static constexpr double pi=3.14;

    public:
    Circle(double rad): rad(rad){};
    double area() const override{
        return pi*rad*rad;
    }

};

class Rectangle : public Shape{
    private:
    double base;
    double hight;
    static constexpr double pi=3.14;

    public:
    Rectangle(double base, double hight) : base(base), hight(hight){};
    double area() const override{
        return base*hight;
    }
};

int main(){
    Circle c1(1);
    Rectangle r1(1,1);
    Circle c2(2);
    Rectangle r2(2,2);
    
    std::cout<<c1.area()<<std::endl;
    std::cout<<r1.area()<<std::endl;

    Shape *array[4] = {&c1, &r1, &c2, &r2};


}