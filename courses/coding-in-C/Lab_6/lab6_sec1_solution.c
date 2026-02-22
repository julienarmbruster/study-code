#include <stdio.h>

int main() {
    FILE *datei = fopen("../sec1.txt", "r");
    if (datei == NULL) {
        printf("Datei konnte nicht geöffnet werden.\n");
        return 1;
    }

    int zeichen;
    while ((zeichen = fgetc(datei)) != EOF) {
        putchar(zeichen); 
    }

    fclose(datei);
    return 0;
}