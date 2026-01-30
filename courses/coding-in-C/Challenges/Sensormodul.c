#include <stdio.h>
unsigned char status=0xa7, pruefung=1, wert=0;

int main(){

    for(int i=0; i<8; i++){
        if((status&pruefung)==1){
            switch(i){
                case 0: wert++; break;
                case 1: wert=wert+2; break;
                case 2: wert=wert+4; break;
                case 3: wert=wert+8; break;
                case 5: printf("---Unterspannung---\n"); break;
                case 6: printf("--Uebertemperatur--\n"); break;
                case 7: printf("------Fehler-------\n"); break;
            }

        }
        pruefung=(pruefung<<1);
    }
    printf("Messwert: %d",wert);
    return 0;

}