#include <stdio.h>
#include <string.h>

int main(){
    /*char arr[] = {"Curly bird catches the worm"};
    char *arrptr = arr;
    printf("%p\n",arrptr);
    printf("%s\n",arrptr);
    *arrptr = 'E';
    arrptr++;
    *arrptr = 'a';
    printf("%s\n",arr);
    printf("%p\n",arrptr);
    */
    char input[100];
    printf("String eingeben: ");
    fgets(input, sizeof(input), stdin);
    char *ptr = input+1;
    *ptr = 'c';
    printf("%s",input);
}