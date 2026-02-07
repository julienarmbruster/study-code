#include <stdio.h>

int main(){
    int myNumbers[5] = {10,20,30,40,50};
    int *p2 = myNumbers + 1;
    int *p5 = myNumbers + 4;
    printf("%p\n",p2);
    printf("%p\n",p5);
    printf("%ld",p5-p2);



}