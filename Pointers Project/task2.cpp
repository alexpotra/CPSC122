/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 16, 2023
 Programming Assignment: PA3
 Description: This program checks if any of the given lottery numbers won.
*/

#include "task2.h"

/*************************************************************
 * Function: findWinningLotteryTicket ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function checks whether one of the
 *              player numbers is the winning lottery number
 * Input parameters: winning ticket number, player numbers,
 *                   number of player numbers
 * Returns: Boolean
 *************************************************************/
bool findWinningLotteryTicket(const int winningTicketNum, const int *playerNumbers, const int numPlayerNumbers)
{
    // linear search player number array for winning ticket number
    for (int i = 0; i < numPlayerNumbers; i++)
    {
        if (*(playerNumbers + i) == winningTicketNum)
        {
            return true;
        }
    }
    return false;
}

/*************************************************************
 * Function: task2 ()
 * Date Created: 2/12/23
 * Date Last Modified: 2/16/23
 * Description: This function runs the check on a lottery
 *              winning number and prints the results.
 * Input parameters: None
 * Returns: None
 *************************************************************/
void task2()
{
    int numbers[] = {13579,
                     26791,
                     26792,
                     33445,
                     55555,
                     62483,
                     77777,
                     79422,
                     85647,
                     93121};
    int numPlayerNumbers = sizeof(numbers) / sizeof(int);
    int winningTicketNum = 0;

    // Get winning ticket number
    cout << "Please enter this week's winning 5-digit number: ";
    cin >> winningTicketNum;

    // Print results
    if (findWinningLotteryTicket(winningTicketNum, numbers, numPlayerNumbers))
    {
        cout << "Congratulations, you have won the lottery!" << endl;
    }
    else
    {
        cout << "Oops, try again next week!" << endl;
    }
}