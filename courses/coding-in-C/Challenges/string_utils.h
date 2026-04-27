#include <stdio.h>
#include <stdlib.h>

int custom_len(char* string) {
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

char* read_line_dynamic(void) {
    char buffer[100];

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }

    int len = custom_len(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i <= len; i++) {
        result[i] = buffer[i];
    }

    return result;
}