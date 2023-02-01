/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: January 31, 2023
 Programming Assignment: PA1                                                                      
 Description: This program converts english text to Morse code or vice versa.
*/

#include "morse.h"

int main()
{
    string conversionType, inputFile, outputFile;
    cout << "What would you like to convert? ";
    cin >> conversionType >> inputFile >> outputFile;

    initConversion();
    if (conversionType == "-m")
    {
        int count = convertToMorse(inputFile, outputFile);
        printResults(inputFile, outputFile, count);
    }
    else
    {
        int count = convertToEnglish(inputFile, outputFile);
        printResults(inputFile, outputFile, count);
    }

    return 0;
}
