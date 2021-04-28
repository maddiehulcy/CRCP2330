#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char *parseLine(char *line);
char *convertToBinary(int n);
void reverseString(char *string, int start, int end);


int main() {
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
        binary = convertToBinary(atoi(line + 1));
        cout << binary << endl;
        strcpy(res, binary);
        free(binary);
    }
    // else C command
    else {
        
    }

    return res;
}


/* Function to reverse string from start to end*/
void reverseString(char *string, int start, int end)
{
    while (start < end)
    {
        char temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}

char *convertToBinary(int n)
{
    // array to store binary number
    char *binaryStr;
    binaryStr = (char*)malloc(17);
    memset(binaryStr, '\0', 17);

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryStr[i] = (n % 2) + 48;
        n = n / 2;
        i++;
    }

    binaryStr[i] = '\0';

    /* pad with zeros */
    char *z = "0";
    while (strlen(binaryStr) < 15) {
        strcat(binaryStr, z);
    }

    reverseString(binaryStr, 0, 14);

    return binaryStr;
}