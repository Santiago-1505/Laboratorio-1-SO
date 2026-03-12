#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wgrepStdin(char *searchTerm);
void wgrepFile(char *searchTerm, char *fileName);
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(EXIT_FAILURE);
    }

    char *searchTerm = argv[1];

    if (argc == 2){
        wgrepStdin(searchTerm);
        exit(EXIT_SUCCESS);
    }
    for (int i = 2; i < argc; i++){
        wgrepFile(searchTerm, argv[i]);
    }

    exit(EXIT_SUCCESS);
}

void wgrepStdin(char *searchTerm){
    char *line = NULL;
    size_t size = 0;

    while (getline(&line, &size, stdin) != -1)
    {
        if (strstr(line, searchTerm) != NULL)
        {
            printf("%s", line);
        }
    }
    free(line);
}

void wgrepFile(char *searchTerm, char *fileName){
    FILE *fptr;
    fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        printf("wgrep: cannot open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t size = 0;

    while (getline(&line, &size, fptr) != -1)
    {
        if (strstr(line, searchTerm) != NULL)
        {
            printf("%s", line);
        }
    }
    free(line);
    fclose(fptr);
}