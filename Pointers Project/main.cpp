/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 16, 2023
 Programming Assignment: PA3
 Description: This program runs all three tasks.
*/

#include "task1.h"
#include "task2.h"
#include "task3.h"

int main()
{
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;

    // Number stats
    task1();

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;

    // Lottery winning number
    task2();

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;

    // Random sentence generator
    task3();

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;

    return 0;
}
