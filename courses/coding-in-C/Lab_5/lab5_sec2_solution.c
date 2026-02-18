#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    // Check if at least one argument provided
    if (argc < 2) {
        printf("Usage: %s <argument1> [argument2] ...\n", argv[0]);
        return 1;
    }

    printf("=== Variant A: Using Array Indexing [] ===\n");
    for (int i = 0; i < argc; i++) {
        printf("Argument %d at address \"%016llX\" has content: %s (length: %zu)\n",
               i, (unsigned long long)argv[i], argv[i], strlen(argv[i]));
    }

    printf("\n=== Variant B: Using Pointer Dereferencing ===\n");
    char **p = argv;
    int index = 0;
    while (p < argv + argc) {
        printf("Argument %d at address \"%016llX\" has content: %s (length: %zu)\n",
               index, (unsigned long long)*p, *p, strlen(*p));
        p++;
        index++;
    }

    return 0;
}