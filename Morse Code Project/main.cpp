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
