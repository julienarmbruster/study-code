#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));
    char random;
    int field[10]={0,0,0,0,1,1,0,0,0,0};
    int *p_field=field;
    int temp[10]={0};
    int *p_temp = temp;

    int try = 1;
    
    while(1){

        int count = 0;
        for(int i = 0; i < 10; i++){
            count += *(p_field + i);
        }
        if(count <= 1) break;  
        
        memset(temp, 0, sizeof(temp)); 
        p_field = field;  
        p_temp = temp;  
        
        for(int i=0; i<10; i++){
            if(*(p_field+i)){  
                random=rand()%2;
                if(random && i!=9){  
                    (*(p_temp+i+1))++;  
                }
                else if(random == 0 && i!=0){  
                    (*(p_temp+i-1))++;  
                }
                else {  
                    (*(p_temp+i))++;
                }
            }
        }

        for(int i=0; i<10; i++){
            if(*(p_temp+i) > 1){
                printf("%d: ",try);
                printf("Collision on index %d\n", i);
                *(p_temp+i) = 0;  
            } else if(*(p_temp+i) == 1){
                *(p_temp+i) = 1;  
            }
        }

        printf("%d: ",try);
        for(int i=0; i<10; i++){
            field[i]=temp[i];
            printf("%d", field[i]);
        }
        printf("\n");
        try++;
    }
    return 0;
}