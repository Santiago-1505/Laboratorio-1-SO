#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>

FILE *fptr;

void comprimir_archivos(char *path);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        comprimir_archivos(argv[i]);
    }

    return EXIT_SUCCESS;
}

void comprimir_archivos(char *path) {
	uint32_t length = 0;
	char current_char;
	char prev;

    FILE *fptr = fopen(path, "r");
    if (fptr == NULL) {
        printf("wzip: cannot open file\n");
        exit(EXIT_FAILURE);
    } while ((current_char = fgetc(fptr)) != EOF) {

		// caso incial
        if (length == 0) {
            prev = current_char;
            length = 1;
        }
		// caso donde el caracter actual es igual al anterior
        else if (current_char == prev) {
            length++;
        }
		// caso donde el caracter actual es distinto del anterior
        else {
            fwrite(&length, sizeof(uint32_t), 1, stdout);
            fwrite(&prev, sizeof(char), 1, stdout);

            prev = current_char;
            length = 1;
        }
    }

    fclose(fptr);
}
