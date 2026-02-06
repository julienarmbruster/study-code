#include <stdio.h>
float add(float var1, float var2);
float sub(float var1, float var2);
float mul(float var1, float var2);
float div(float var1, float var2);

int main(){
    float var1, var2;
    char operator;
    printf("Bitte zwei Kommazahlen eingeben:\n1:");
    scanf("%f",&var1);
    printf("2:");
    scanf("%f",&var2);
    printf("Bitte Operator eingeben:\n");
    scanf(" %c", &operator);
    switch (operator){
        case '+': printf("= %f\n", add(var1,var2)); break;
        case '-': printf("= %f\n", sub(var1,var2)); break;
        case '*': printf("= %f\n", mul(var1,var2)); break;
        case '/': printf("= %f\n", div(var1,var2)); break;
        default: printf("Kein gueltiger Operator\n"); break;

    }
    return 0;
}
float add(float var1, float var2){
    return var1+var2;
}
float sub(float var1, float var2){
    return var1-var2;
}
float mul(float var1, float var2){
    return var1*var2;
}
float div(float var1, float var2){
    if(var2==0.0f){
        printf("Division durch null ERROR! ");
    }
    return var1/var2;
}