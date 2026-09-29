#include <iostream>
#include <cmath>

class Vector2D{
private:
    double x;
    double y;

public:
    Vector2D() : x(1), y(1){};
    Vector2D(double x, double y) : x(x), y(y){};

    Vector2D operator+(Vector2D& other){
        return Vector2D(this->x+other.x, this->y+other.y);
    }

    Vector2D& operator+=(const Vector2D& secVector){
        this->x=this->x + secVector.x;
        this->y=this->y + secVector.y;
        return *this;
    }

    Vector2D operator*(double s){
        return Vector2D(x*s, y*s);
    }

    friend Vector2D operator*(double s, const Vector2D& vec){
        return Vector2D(s*vec.x, s*vec.y);
    }

    bool operator<(const Vector2D& other){
        return this->calculateLength()<other.calculateLength();
    }

    bool operator>(const Vector2D& other){
        return this->calculateLength()>other.calculateLength();
    }


    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    void printVector(){
        std::cout<<"x: "<<x<<"\n"<<"y: "<<y<<std::endl;

    }

    double calculateLength()const{
        return sqrt(x*x+y*y);
    }

    double calculateLength(int precision)const{
        double factor = std::pow(10.0, precision);
        return std::round(calculateLength() * factor) / factor;
    }
};



int main(){
    Vector2D v1(2,5);
    Vector2D v2(4,6);
    Vector2D v3 = v1+v2;
    v3.printVector();
    v1+=v2;
    v1.printVector();
    v1=10*v1;
    v1.printVector();
    if(v1<v2){
        std::cout<<"groeser"<<std::endl;
    }

}