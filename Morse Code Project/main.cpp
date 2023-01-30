#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
string morseStrings[91];
void initArray();

int main()
{
    initArray();
    return 0;
}

void initArray()
{
    morseStrings['A'] = ".-";
    morseStrings['B'] = "-...";
    morseStrings['C'] = "-.-.";
    morseStrings['D'] = "-..";
    morseStrings['E'] = ".";
    morseStrings['F'] = "..-.";
    morseStrings['G'] = "--.";
    morseStrings['H'] = "....";
    morseStrings['I'] = "..";
    morseStrings['J'] = ".---";
    morseStrings['K'] = "-.-";
    morseStrings['L'] = ".-..";
    morseStrings['M'] = "--";
    morseStrings['N'] = "-.";
    morseStrings['O'] = "---";
    morseStrings['P'] = ".--.";
    morseStrings['Q'] = "--.-";
    morseStrings['R'] = ".-.";
    morseStrings['S'] = "...";
    morseStrings['T'] = "-";
    morseStrings['U'] = "..-";
    morseStrings['V'] = "...-";
    morseStrings['W'] = ".--";
    morseStrings['X'] = "-..-";
    morseStrings['Y'] = "-.--";
    morseStrings['Z'] = "--..";
    morseStrings['0'] = "-----";
    morseStrings['1'] = ".----";
    morseStrings['2'] = "..---";
    morseStrings['3'] = "...--";
    morseStrings['4'] = "....-";
    morseStrings['5'] = ".....";
    morseStrings['6'] = "-....";
    morseStrings['7'] = "--...";
    morseStrings['8'] = "---..";
    morseStrings['9'] = "----.";
}