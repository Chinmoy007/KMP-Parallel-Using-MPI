#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("text.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    getline(&line, &len, fp);
    printf("%s", line);
    int size = strlen(line);
    printf("size %d\n", size);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

}