/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 16, 2023
 Programming Assignment: PA3
 Description: This program generates random sentences from a provided word bank.
*/

#include <stdlib.h>
#include <time.h>
#include "task3.h"

/*************************************************************
 * Function: sortWords ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function alphabetically sorts the string
 *              array.
 * Input parameters: String array pointer, size of array
 * Returns: None
 *************************************************************/
void sortWords(string *arr, const int size)
{
    // bubble sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            string first = *(arr + i);
            string second = *(arr + j);

            if (first.compare(second) > 0)
            {
                string temp = first;
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

/*************************************************************
 * Function: createWordsArray ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function reads the words from the file,
 *              puts them into a string array, and sorts them.
 * Input parameters: input file, size of array
 * Returns: String array pointer
 *************************************************************/
string *createWordsArray(ifstream &inFile, const int size)
{
    string *result = new string[size];

    for (int i = 0; i < size; i++)
    {
        inFile >> *(result + i);
    }

    sortWords(result, size);

    return result;
}

/*************************************************************
 * Function: getRandomWord ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function chooses a random word from a
 *              string array.
 * Input parameters: string array pointer, size of array
 * Returns: string
 *************************************************************/
string getRandomWord(const string *arr, int size)
{
    int random = rand() % size;
    return arr[random];
}

/*************************************************************
 * Function: generateSentance ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function generates a random sentence using
 *              the given POS's and in the following order:
 *              article noun verb prep article noun.
 * Input parameters: result sentence, article array, size of
 *                   article array, noun array, size of noun
 *                   array, verb array, size of verb array,
 *                   prep array, size of prep array
 * Returns: None
 *************************************************************/
void generateSentence(string *sentence,
                      const string *articlesArr, const int articlesSize,
                      const string *nounsArr, const int nounsSize,
                      const string *verbsArr, const int verbsSize,
                      const string *prepsArr, const int prepsSize)
{
    sentence[0] = getRandomWord(articlesArr, articlesSize);
    sentence[0][0] = toupper(sentence[0][0]);
    sentence[1] = getRandomWord(nounsArr, nounsSize);
    sentence[2] = getRandomWord(verbsArr, verbsSize);
    sentence[3] = getRandomWord(prepsArr, prepsSize);
    sentence[4] = getRandomWord(articlesArr, articlesSize);
    sentence[5] = getRandomWord(nounsArr, nounsSize);
}

/*************************************************************
 * Function: printWords ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function outputs the words of the given
 *              string array.
 * Input parameters: String array pointer, size of array,
 *                   exlamation point condition
 * Returns: None
 *************************************************************/
void printWords(string *arr, const int size, bool printExclamation = false)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i);
        if (i != size - 1)
        {
            cout << " ";
        }
    }
    if (printExclamation)
    {
        cout << "!";
    }
    cout << endl;
}

/*************************************************************
 * Function: task3 ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function runs the program to generate
 *              random sentences using the word bank from
 *              an input file.
 * Input parameters: None
 * Returns: None
 *************************************************************/
void task3()
{
    // set up & check input file
    ifstream input;
    input.open("input_words.txt");
    if (!input.is_open())
    {
        cout << "Input file failed to open" << endl;
        exit(-1);
    }

    srand(time(NULL));

    int numSentences = 0;

    string *articles = NULL;
    int articleSize = 0;

    string *nouns = NULL;
    int nounSize = 0;

    string *verbs = NULL;
    int verbSize = 0;

    string *prepositions = NULL;
    int prepositionSize = 0;

    input >> numSentences;

    // Fill POS arrays
    string wordType;
    while (input >> wordType)
    {
        cout << wordType << ": ";
        if (wordType == "Articles")
        {
            input >> articleSize;
            articles = createWordsArray(input, articleSize);
            printWords(articles, articleSize);
        }
        else if (wordType == "Nouns")
        {
            input >> nounSize;
            nouns = createWordsArray(input, nounSize);
            printWords(nouns, nounSize);
        }
        else if (wordType == "Verbs")
        {
            input >> verbSize;
            verbs = createWordsArray(input, verbSize);
            printWords(verbs, verbSize);
        }
        else if (wordType == "Prepositions")
        {
            input >> prepositionSize;
            prepositions = createWordsArray(input, prepositionSize);
            printWords(prepositions, prepositionSize);
        }
    }

    cout << endl;

    // Generate & Output Sentences
    for (int i = 0; i < numSentences; i++)
    {
        // Generate sentence
        const int sentenceLength = 6;
        string *sentence = new string[sentenceLength];
        generateSentence(sentence, articles, articleSize, nouns, nounSize, verbs, verbSize, prepositions, prepositionSize);

        // Output Sentence
        cout << (i + 1) << ". ";
        printWords(sentence, sentenceLength, true);

        delete[] sentence;
    }

    // Free memory
    delete[] articles;
    delete[] nouns;
    delete[] verbs;
    delete[] prepositions;
}