#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int n;
    printf("Bitte eine Zahl eingeben: ");
    scanf("%d", &n);

    int *p_n = calloc( n, sizeof *p_n);
    if (p_n == NULL) {
        return 1;
    }
    for(int i=0;i<n;i++){
        *(p_n + i) = i*i;
        printf("%d", *(p_n+i));
    }
    printf("\n");
    int *tmp = realloc(p_n, 2*n*sizeof(*p_n));
    for(int i=0;i<n*2;i++){
        *(p_n + i) = i*i;
        printf("%d", *(p_n+i));
    }
    
    free(p_n);
    return 0;

}