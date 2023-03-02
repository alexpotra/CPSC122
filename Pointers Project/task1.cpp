/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 16, 2023
 Programming Assignment: PA3
 Description: This program checks if a number is a multiple of 7, 11, or 13,
              if the sum of the digits is odd or even, and if the number is
              a prime number.
*/

#include "task1.h"

/*************************************************************
 * Function: checkMultiple ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function checks if the number is a
 *              multiple of 7, 11, or 13.
 * Input parameters: Integer
 * Returns: Boolean
 *************************************************************/
bool checkMultiple(int num)
{
    // Is the value a multiple of 7, 11, or 13?
    return (num % 7 == 0 || num % 11 == 0 || num % 13 == 0);
}

/*************************************************************
 * Function: checkSumEven ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function checks if the sum of the digits
 *              of the number is even.
 * Input parameters: Integer number
 * Returns: Boolean
 *************************************************************/
bool checkSumEven(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }

    // Is the sum of the digits odd or even?
    return (sum % 2 == 0);
}

/*************************************************************
 * Function: checkPrime ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function checks if the number is prime.
 * Input parameters: Integer number
 * Returns: Boolean
 *************************************************************/
bool checkPrime(int num)
{
    // Is the value a prime number?
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

/*************************************************************
 * Function: getBoolStr ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function returns the bool value as a
 *              string.
 * Input parameters: Boolean
 * Returns: String
 *************************************************************/
string getBoolStr(bool value)
{
    return (value ? "true" : "false");
}

/*************************************************************
 * Function: answerIntegerQuestions ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function completes all of the above checks
 *              on a number.
 * Input parameters: number, isMultiple, isSumEven, isPrime
 * Returns: None
 *************************************************************/
void answerIntegerQuestions(const int num, bool *isMultiple, bool *isSumEven, bool *isPrime)
{
    *isMultiple = checkMultiple(num);
    *isSumEven = checkSumEven(num);
    *isPrime = checkPrime(num);
}

/*************************************************************
 * Function: task1 ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function runs the checks on an
 *              input file with numbers and prints the results.
 * Input parameters: None
 * Returns: None
 *************************************************************/
void task1()
{
    // set up & check input file
    ifstream input;
    input.open("numbers.txt");
    if (!input.is_open())
    {
        cout << "Input file failed to open" << endl;
        exit(-1);
    }

    while (!input.eof())
    {
        int num = 0;
        bool isMultiple = false, isSumEven = false, isPrime = false;
        input >> num;
        answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);

        // print results
        cout << num << " isMultiple: " << getBoolStr(isMultiple) << " isSumEven: " << getBoolStr(isSumEven) << " isPrime: " << getBoolStr(isPrime) << endl;
    }

    // close file
    input.close();
}
