#include <iostream>
#include <cmath>

class Vector2D
{
    private:
    double x;
    double y;

    public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double xValue, double yValue)
    {
        x = xValue;
        y = yValue;
    }

    double getXValue() const {
        return x;
    }

    double getYValue() const {
        return y;
    }

    void printVector() const {
        std::cout<<"x:"<<x<<std::endl;
        std::cout<<"y:"<<y<<std::endl;
    }

    double length(){
        return sqrt(x*x+y*y);
    }

    double length(int precision){
        double length = sqrt(x*x+y*y);
        double factor = std::pow(10.0, precision);
        return std::round(length * factor) / factor;
    }
};

int main(){
    Vector2D vec1(1,1);
    std::cout<<vec1.length()<<std::endl;
    std::cout<<vec1.length(2)<<std::endl;
}