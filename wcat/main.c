#include "stdio.h"
#include "stdlib.h"

FILE *fptr;

void leer_archivo(char *path);
void escribir_archivo(char *path);

int main(int argc, char *argv[]) {
    if (argc == 1){
        return EXIT_SUCCESS;
    }

    for (int i = 1; i < argc; i++){
        leer_archivo(argv[i]);
    }
    
    return EXIT_SUCCESS;
}

void leer_archivo(char *path) {

    fptr = fopen(path, "r");
    if (fptr == NULL) {
        printf("wcat:cannot open file %s\n", path);
        exit(EXIT_FAILURE);
    } else {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), fptr)) {
        printf("%s", buffer);
        }
        fclose(fptr);
    }
}
