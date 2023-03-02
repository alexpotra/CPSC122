/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: January 31, 2023
 Programming Assignment: PA1                                                                      
 Description: This file contains conversion functions and utility functions.
*/

#include "morse.h"

// array with English character to Morse code mapping
string morseStrings[91];

/*************************************************************
 * Function: initConversion ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function initializes the internal array.                    	
 * Input parameters: None    	
 * Returns: None           	      
 *************************************************************/
void initConversion()
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
    morseStrings[' '] = " ";
    morseStrings['\n'] = "\n";
}

/*************************************************************
 * Function: printFile ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function prints the contents of the file.                    	
 * Input parameters: file name    	
 * Returns: None           	      
 *************************************************************/
void printFile(const string &fileName)
{
    // set up & check input file
    ifstream input;
    input.open(fileName);
    if (!input.is_open())
    {
        cout << "Input file failed to open" << endl;
        exit(-1);
    }

    cout << endl
         << fileName << endl
         << endl;

    string line;
    while (getline(input, line))
    {
        cout << line << endl;
    }

    input.close();
}

/*************************************************************
 * Function: printResults ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function outputs the conversion results 
 *              to standard output.                    	
 * Input parameters: input file, output file, total character 
 *              count    	
 * Returns: None           	      
 *************************************************************/
void printResults(const string &inputFile, const string &outputFile, int numLetters)
{
    printFile(inputFile);
    printFile(outputFile);
    cout << endl
         << "Total characters converted successfully (including newline and white spaces): " << numLetters << endl;
}

/*************************************************************
 * Function: convertToMorse ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function converts English text to Morse 
 *              code.                    	
 * Input parameters: input file, output file    	
 * Returns: number of characters converted           	      
 *************************************************************/
int convertToMorse(const string &inputFile, const string &outputFile)
{
    int numLetters = 0;

    // set up & check input file
    ifstream input;
    input.open(inputFile);
    if (!input.is_open())
    {
        cout << "Input file failed to open" << endl;
        exit(-1);
    }

    // set up & check output file
    ofstream output;
    output.open(outputFile);
    if (!output.is_open())
    {
        cout << "Output file failed to open" << endl;
        exit(-1);
    }

    // read characters from file
    char ch;
    while (input.get(ch))
    {
        ch = toupper(ch);
        numLetters++;
        output << morseStrings[ch];
        if ((ch != ' ') && (ch != '\n'))
        {
            output << " ";
        }
    }

    // close files
    input.close();
    output.close();

    return numLetters;
}

/*************************************************************
 * Function: searchMorse ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function searches the English character 
 *              corresponding to the Morse equivalent.                   	
 * Input parameters: Morse character    	
 * Returns: English character          	      
 *************************************************************/
char searchMorse(const string &morse)
{
    if (morse.empty() || morse == "/")
    {
        return ' ';
    }
    for (char i = 32; i < 91; i++)
    {
        if (morseStrings[i] == morse)
        {
            return i;
        }
    }
    return 0;
}

/*************************************************************
 * Function: convertToEnglish ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function converts Morse code to English
 *              text.                    	
 * Input parameters: input file, output file    	
 * Returns: number of characters converted           	      
 *************************************************************/
int convertToEnglish(const string &inputFile, const string &outputFile)
{
    int numLetters = 0;

    // set up & check input file
    ifstream input;
    input.open(inputFile);
    if (!input.is_open())
    {
        cout << "Input file failed to open" << endl;
        exit(-1);
    }

    // set up & check output file
    ofstream output;
    output.open(outputFile);
    if (!output.is_open())
    {
        cout << "Output file failed to open" << endl;
        exit(-1);
    }

    // read morse code from file
    char ch;
    string morse;
    while (input.get(ch))
    {
        if (ch != ' ' && ch != '\n')
        {
            morse += ch;
        }
        else
        {
            numLetters++;
            output << searchMorse(morse);
            if (ch == '\n')
            {
                numLetters++;
                output << endl;
            }
            morse.clear();
        }
    }

    // close files
    input.close();
    output.close();

    return numLetters;
}
