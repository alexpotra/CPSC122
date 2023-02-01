#include "morse.h"

string morseStrings[91];

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

void printResults(const string &inputFile, const string &outputFile, int numLetters)
{
    printFile(inputFile);
    printFile(outputFile);
    cout << endl
         << "Total characters converted successfully (including newline and white spaces): " << numLetters << endl;
}

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
