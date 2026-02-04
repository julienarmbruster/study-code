#include <stdio.h>

int main(){
    unsigned char r, s;
    for(r=8;r>0;r--){
        for(s=65;s<=72;s++){
            printf("%c%-2.d",s ,r);
            
        }
        printf("\n");
    }
    return 0;
}