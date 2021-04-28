#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char *parse_line(char *line);

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


}