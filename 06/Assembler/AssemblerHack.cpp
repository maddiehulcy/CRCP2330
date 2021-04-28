#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char *parseLine(char *line);

int main(void) {
    FILE *input_file_pointer;
    FILE *output_file_pointer;
    char *line = NULL;
    char *binary_string = NULL;
    size_t len = 0;
    ssize_t read = 0;
    ssize_t next_read = 0;

    input_file_pointer = fopen("C:/Users/maddi/Documents/CRCP2330/nand2tetris/projects/06/add/Add.asm", "r");
    output_file_pointer = fopen("C:/Users/maddi/Documents/CRCP2330/nand2tetris/projects/06/add/Add.hack", "w");

    getline(&line, &len, input_file_pointer);
    cout << *line << endl;
    while (next_read != -1) {
        binary_string = parseLine(line);
        next_read = getline(&line, &len, input_file_pointer);

        if (strlen(binary_string) == 0) { continue; }

        if (next_read != -1) { strcat(binary_string, "\n"); }

        fputs(binary_string, output_file_pointer);
    }
    fclose(input_file_pointer);
    free(line);
    free(binary_string);

    return 0;
}

char *parseLine(char *line) {
    /* each output is no more than 16 bits */
    char *res = (char*)malloc(18);
    memset(res, '\0', 18);

    char *binary;

    // ignore whitespaces and comments
    if (line[0] == '/' || strlen(line) == 2) {
        //printf("not to process\n");
    }

    // if A command
    if (line[0] == '@') {

    }
    // else C command

    return res;
}