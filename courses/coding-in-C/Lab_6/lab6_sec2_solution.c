#include <stdio.h>

struct car {
    float fuel_level, max_fuel_level;
    char* model;
};

void refuel(struct car *car_ptr, float amount){
    float new_level = (*car_ptr).fuel_level + amount;
    if (new_level > (*car_ptr).max_fuel_level) {
        (*car_ptr).fuel_level = (*car_ptr).max_fuel_level;
    } else {
        (*car_ptr).fuel_level = new_level;
    }
}

int main(){
    struct car low_car;
    low_car.fuel_level = 23.4f;
    low_car.max_fuel_level = 44.0f;
    refuel(&low_car, 10.0f);
    printf("Aktueller Tankinhalt: %.2f\n", low_car.fuel_level);
    
    return 0;
}