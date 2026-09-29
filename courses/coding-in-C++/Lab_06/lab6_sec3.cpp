#include "device.hpp"

int main(){
    Device d1("Speaker1", "Speaker",0);
    d1.print_info();
    d1.turn_on();
    d1.print_info();
}