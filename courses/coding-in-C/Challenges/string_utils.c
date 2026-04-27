#include "string_utils.h"
int main() {
    printf("String eingeben: ");
    char* input = read_line_dynamic();
    if (input != NULL) {
        printf("Sie haben eingegeben: %s\n", input);
        free(input);
    } 
    return 0;
}