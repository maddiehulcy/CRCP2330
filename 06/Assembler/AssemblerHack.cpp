#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

string parseLine(string line, map<string, string> &comp, map<string, string> &dest, map<string, string> &jump, map<string, int> &standard) {

string convertToBinary(int n);
void reverseString(char *string, int start, int end);
string handleC(char* line);
void makeMaps(map<string, string> &comp, map<string, string> &dest, map<string, string> &jump,
              map<string, int> &standard);


int main(int argc, char** argv) {
    map<string, string> comp;
    map<string, string> dest;
    map<string, string> jump;
    map<string, int> standard;
    makeMaps(comp, dest, jump, standard);
    string inFileName = argv[1];
    int nameP1 = inFileName.find_last_of('/') + 1;
    int nameP2 = inFileName.length() - nameP1 - 4;
    string outFileName = inFileName.substr(nameP1, nameP2);
    ifstream input;
    input.open(argv[1]);
    string fileLine;
    while(getline(input, fileLine)){
        string binaryLine = parseLine(fileLine, comp, dest, jump, standard);
    }
    return 0;


    return 0;
}

string parseLine(string line, map<string, string> &comp, map<string, string> &dest, map<string, string> &jump, map<string, int> &standard) {
    string binary;
    if(line[0] == '/' || line.length() <= 2){
        return "";
    }
    //Normalize lines
    line = line.substr(0, line.length() - 1);
    if(line[0] == ' '){
        int i = 0;
        while(line[i] == ' '){
            ++i;
        }
        line = line.substr(i, line.length());
    }
    int commCheck;
    for(int i = 0; i < line.length(); ++i){
        if(line[i] == ' '){
            commCheck = i;
            break;
        }
    }
    line = line.substr(0, commCheck);
    //A instruction
    if (line[0] == '@') {
        string passStr;
        for(int i = 1; i < line.length(); ++i){
            if(isnumber(line[i])){
                passStr += line[i];
            }
        }
        if(passStr.length() == 0){
            string checkMap = line.substr(1, line.length() - 1);
            binary = aInstruction(standard[checkMap]);
        } else{
            binary = aInstruction(stoi(passStr));
        }
    } else {
        binary = cInstruction(line,comp, dest, jump);
    }
    cout << binary << endl;
    return binary;
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