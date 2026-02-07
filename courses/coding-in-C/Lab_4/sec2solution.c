#include <stdio.h>
#include <string.h>

int main(){
    char input[100];
    
    printf("Bitte Wort eingeben (max. 100 Zeichen):");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    
    char *front = input;
    char *back = input + strlen(input) - 1; 

    while(((*front|32)==(*back|32)) && front < back){
        front++;
        back--;
    }
    if(front == back || front > back)
        printf("Das Wort \"%s\" ist ein Palindrom\n", input);
    else
        printf("Das Wort \"%s\" ist kein Palindrom\n", input);
    return 0;
}