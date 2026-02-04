#include <stdio.h>

void ABC();
void line();
void row(char r);

int main(){
    
    ABC();
    for(char r=8; r>0 ;r--){
        line();
        row(r);
    }
    line();
    ABC();
    return 0;
}
void ABC(){
    unsigned char s;
    printf("%2c",1);
    for(s=65;s<=72;s++){
            printf("%4c",s);
        }
    printf("\n");
}
void line(){
    printf("%3c",1);
    for(int i=0;i<8;i++)
    printf("+---");
    printf("+\n");
}
void row(char r){
    unsigned char s;
    printf("%d |",r);
    for(s=65;s<=72;s++){
            if((s+r)%2)printf("###");
            else printf("%4c",1);
            printf("|");
        }
        printf("%2d\n",r);
}

