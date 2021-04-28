#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string parseLine(char *line);
string convertToBinary(int n);
void reverseString(char *string, int start, int end);
string handleC(char* line);


int main() {
    ifstream *input_file_pointer;
    ofstream *output_file_pointer;
    string line = "";
    string binary_string = "";
    size_t len = 0;
    ssize_t read = 0;
    ssize_t next_read = 0;

    input_file_pointer.open("C:/Users/maddi/Documents/CRCP2330/nand2tetris/projects/06/add/Add.asm");
    output_file_pointer.open("C:/Users/maddi/Documents/CRCP2330/nand2tetris/projects/06/add/Add.hack");

    getline(line, input_file_pointer);
    while (next_read != -1) {
        binary_string = parseLine(line);
        next_read = getline(&line, &len, input_file_pointer);

        if (binary_string.length() == 0) { continue; }

        if (next_read != -1) { strcat(binary_string, "\n"); }

        fputs(binary_string, output_file_pointer);
    }
    fclose(input_file_pointer);


    return 0;
}

string parseLine(string line) {
    /* each output is no more than 16 bits */
    char *res = (char*)malloc(18);
    memset(res, '\0', 18);

    char *binary;

    // ignore whitespaces and comments
    if (line[0] == '/' || line.length() == 2) {
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
void reverseString(string str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

string convertToBinary(int n)
{
    // array to store binary number
    string binaryStr;


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
    while (binaryStr.length() < 15) {
        binaryStr.append(z);
    }

    reverseString(binaryStr, 0, 14);

    return binaryStr;
}


void makeMaps(map<string, string> &comp, map<string, string> &dest, map<string, string> &jump,
              map<string, int> &standard){
    comp["0"] = "0101010";
    comp["-1"] = "0111010";
    comp["D"] = "0001100";
    comp["A"] = "0110000";
    comp["!D"] = "0001101";
    comp["!A"] = "0110001";
    comp["-D"] = "0001111";
    comp["-A"] = "0110011";
    comp["D+1"] = "0011111";
    comp["A+!"] = "0110111";
    comp["D-1"] = "0001110";
    comp["A-1"] = "0110010";
    comp["D+A"] = "0000010";
    comp["D-A"] = "0010011";
    comp["A-D"] = "0000111";
    comp["D&A"] = "0000000";
    comp["D|A"] = "0010101";
    comp["M"] = "1110000";
    comp["!M"] = "1110001";
    comp["-M"] = "1110011";
    comp["M+1"] = "1110111";
    comp["M-1"] = "1110010";
    comp["D+M"] = "1000010";
    comp["D-M"] = "1010011";
    comp["M-D"] = "1000111";
    comp["D&M"] = "1000000";
    comp["D|M"] = "1010101";
    dest["null"] = "000";
    dest["M"] = "001";
    dest["D"] = "010";
    dest["A"] = "100";
    dest["MD"] = "011";
    dest["AM"] = "101";
    dest["AD"] = "110";
    dest["AMD"] = "111";
    jump["null"] = "000";
    jump["JGT"] = "001";
    jump["JEQ"] = "010";
    jump["JGE"] = "011";
    jump["JLT"] = "100";
    jump["JNE"] = "101";
    jump["JLE"] = "110";
    jump["JMP"] = "111";
    standard["SP"] = 0;
    standard["LCL"] = 1;
    standard["ARG"] = 2;
    standard["THIS"] = 3;
    standard["THAT"] = 4;
    standard["SCREEN"] = 16384;
    standard["KBD"] = 24576;
}