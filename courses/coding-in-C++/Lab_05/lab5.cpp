#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
/*

template <typename T>
void printArr(T data[]){
    for(int i=0; i<data.size(); i++){
        std::cout<<data[i]<<std::endl;
    }
}

template <typename T>
T detectWeakest(T data[]){
    T small = min_element(data.begin(), data.end());
    return small;
}
*/

//Task 6
void task6(){
    std::vector<int> data{42, 17, 42, 5, 99, 17, 63, 12};
    for(const int& d : data){
        std::cout<<d;
    }
    std::cout<<std::endl;
    sort(data.begin(), data.end());
    for(const int& d : data){
        std::cout<<d;
    }
    std::cout<<std::endl;
    auto value = find(data.begin(), data.end(), 63);
    std::cout<<*value<<std::endl;
}

void task7(){
    std::vector<int> data = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    replace(data.begin(), data.end(), (int)-1, (int)0);
    int amount = count(data.begin(), data.end(), 8);
    for(const int& d : data){
        std::cout<<d;
    }
    std::cout<<std::endl;
    std::cout<<amount<<std::endl;
}

void task8(){
    std::vector<int> data = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    for (auto it = data.begin(); it != data.end(); ++it) {
        std::cout << *it << "\n";
    }
}

int main(){
    task6();
    task7();
}