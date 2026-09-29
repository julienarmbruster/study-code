#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename A, int size>
void printArray(A (&array)[size]){
    for(int i=0; i<size; i++){
        std::cout<<array[i]<<std::endl;
    }
}

template<typename A, int size>
A smallest(A (&array)[size]){
    A small=array[0];
    for(int i=0; i<size; i++){
        if(small>array[i]){
            small=array[i];
        }
    }
    return small;

}

template<typename T1, typename T2>
void printInfo(std::string label1, T1 value1, std::string label2, T2 value2){
    std::cout<<label1<<": "<<value1<<" | "<<label2<<": "<<value2<<std::endl;
}

template<typename V>
void printData(std::vector<V> &data){
    std::cout<<"original data:";
    for(V value : data){
        std::cout<<value<<", ";
    }
    std::cout<<std::endl;
}

template<typename V>
void sortData(std::vector<V> &data){
    sort(data.begin(), data.end());
    std::cout<<"sorted data:";
    for(V value : data){
        std::cout<<value<<", ";
    }
    std::cout<<std::endl;
}

template<typename V>
bool searchValue(std::vector<V> &data, V searchValue){
    for(V value : data){
        if(value == searchValue){
            return 1;
        }
    }
}

template<typename V>
bool iteratePrint(std::vector<V> &data){
    for(auto it = data.begin(); it != data.end(); it++){
        std::cout<<*it<<std::endl;
    }
}



int main(){
    int a = 10;
    int b = 5;
    std::cout<<a<<b<<std::endl;
    swap(a,b);
    std::cout<<a<<b<<std::endl;
    int array[]={6,2,3,4,5};
    printArray(array);
    std::cout<<"Smallest:"<<smallest(array)<<std::endl;
    std::string channel = "motor_temp";
    double motor_temp=50;
    printInfo("Channel",channel,"Value", motor_temp);

    std::vector<int> data = {42, 17, 42, 5, 99, 17, 63, 12};
    printData(data);
    sortData(data);
    if(searchValue(data, 63)){
        std::cout<<"gefunden"<<std::endl;
    }
    iteratePrint(data);
}