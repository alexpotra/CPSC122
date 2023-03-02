/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 7, 2023
 Programming Assignment: PA2
 Description: This file declares sorting and vector functions.
*/

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Performance Metrics type used to track performance counters
struct PerformanceMetrics
{
    int dataComp = 0;
    int loopComp = 0;
    int dataAssign = 0;
    int loopAssign = 0;
    int otherOps = 0;

    int total()
    {
        return dataComp + loopComp + dataAssign + loopAssign + otherOps;
    }
};

/*************************************************************
 * Function: makeAscendingVector ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function creates an ascending sorted
 *              integer vector.
 * Input parameters: Size of vector
 * Returns: An integer vector
 *************************************************************/
vector<int> makeAscendingVector(size_t size);

/*************************************************************
 * Function: makeDescendingVector ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function creates a descending sorted
 *              integer vector.
 * Input parameters: Size of vector
 * Returns: An integer vector
 *************************************************************/
vector<int> makeDescendingVector(size_t size);

/*************************************************************
 * Function: makeRandomVector ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function creates a vector with random
 *              integer values.
 * Input parameters: Size of vector
 * Returns: An integer vector
 *************************************************************/
vector<int> makeRandomVector(size_t size);

/*************************************************************
 * Function: selectionSort ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function sorts a given vector using the
 *              selection sorting algorithm.
 * Input parameters: An integer vector, Performance Metrics
 *                   struct.
 * Returns: Execution time in seconds
 *************************************************************/
double selectionSort(vector<int> &data, PerformanceMetrics &pm);

/*************************************************************
 * Function: optimizedBubbleSort ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function sorts a given vector using the
 *              bubble sorting algorithm with early exit.
 * Input parameters: An integer vector, Performance Metrics
 *                   struct.
 * Returns: Execution time in seconds
 *************************************************************/
double optimizedBubbleSort(vector<int> &data, PerformanceMetrics &pm);

/*************************************************************
 * Function: insertionSort ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function sorts a given vector using the
 *              insertion sorting algorithm.
 * Input parameters: An integer vector, Performance Metrics
 *                   struct.
 * Returns: Execution time in seconds
 *************************************************************/
double insertionSort(vector<int> &data, PerformanceMetrics &pm);

#endif