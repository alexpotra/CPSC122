/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 7, 2023
 Programming Assignment: PA2
 Description: This file contains sorting and vector functions.
*/

#include "sort.h"

/*************************************************************
 * Function: makeAscendingVector ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function creates an ascending sorted
 *              integer vector.
 * Input parameters: Size of vector
 * Returns: An integer vector
 *************************************************************/
vector<int> makeAscendingVector(size_t size)
{
    vector<int> result(size);
    for (int i = 0; i < size; i++)
    {
        result[i] = i;
    }

    return result;
}

/*************************************************************
 * Function: makeDescendingVector ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function creates a descending sorted
 *              integer vector.
 * Input parameters: Size of vector
 * Returns: An integer vector
 *************************************************************/
vector<int> makeDescendingVector(size_t size)
{
    vector<int> result(size);
    for (int i = size - 1; i >= 0; i--)
    {
        result[i] = i;
    }

    return result;
}

/*************************************************************
 * Function: makeRandomVector ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function creates a vector with random
 *              integer values.
 * Input parameters: Size of vector
 * Returns: An integer vector
 *************************************************************/
vector<int> makeRandomVector(size_t size)
{
    vector<int> result(size);
    for (int i = 0; i < size; i++)
    {
        result[i] = rand();
    }

    return result;
}

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
double selectionSort(vector<int> &data, PerformanceMetrics &pm)
{
    auto start = high_resolution_clock::now();

    // initialize loop variable and initial comparison
    pm.loopAssign++; // i = 0
    pm.loopComp++;   // i < data.size() - 1
    pm.otherOps++;   // data.size() - 1
    for (int i = 0; i < data.size() - 1; i++)
    {
        int min = i;
        pm.dataAssign++;

        // initialize loop variable and initial comparison
        pm.loopAssign++; // j = i + 1
        pm.loopComp++;   // j < data.size()
        for (int j = i + 1; j < data.size(); j++)
        {
            pm.dataComp++;
            if (data[j] < data[min])
            {
                min = j;
                pm.dataAssign++;
            }

            // incrementaion and loop conditional
            pm.loopAssign++; // j++
            pm.loopComp++;   // j < data.size()
        }

        int temp = data[min];
        data[min] = data[i];
        data[i] = temp;
        pm.dataAssign += 3;

        // incrementaion and loop conditional
        pm.loopAssign++; // i++
        pm.loopComp++;   // i < data.size() - 1
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    return duration.count() / (double)1e9;
}

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
double optimizedBubbleSort(vector<int> &data, PerformanceMetrics &pm)
{
    auto start = high_resolution_clock::now();

    // initialize loop variable and initial comparison
    pm.loopAssign++; // i = 0
    pm.loopComp++;   // i < data.size()
    for (int i = 0; i < data.size(); i++)
    {
        bool unsorted = true;
        pm.dataAssign++;

        // initialize loop variable and initial comparison
        pm.loopAssign++; // j = 0
        pm.loopComp++;   // j < data.size() - i - 1
        for (int j = 0; j < data.size() - i - 1; j++)
        {
            pm.dataComp++; // data[j] > data[j + 1]
            if (data[j] > data[j + 1])
            {
                unsorted = false;
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                pm.dataAssign += 4;
            }

            // incrementaion and loop conditional
            pm.loopAssign++; // j++
            pm.loopComp++;   // j < data.size() - i - 1
        }

        pm.dataComp++;
        if (unsorted)
        {
            break;
        }

        // incrementaion and loop conditional
        pm.loopAssign++; // i++
        pm.loopComp++;   // i < data.size()
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    return duration.count() / (double)1e9;
}

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
double insertionSort(vector<int> &data, PerformanceMetrics &pm)
{
    auto start = high_resolution_clock::now();

    // initialize loop variable and initial comparison
    pm.loopAssign++; // i = 1
    pm.loopComp++;   // i < data.size()
    for (int i = 1; i < data.size(); i++)
    {
        int curr = data[i];
        pm.dataAssign++;
        int j = i - 1;
        pm.dataAssign++;

        pm.loopComp += 2;
        pm.otherOps++; // &&
        while (j >= 0 && data[j] > curr)
        {
            data[j + 1] = data[j];
            j--;
            pm.dataAssign += 2;

            pm.loopComp += 2;
            pm.otherOps++; // &&
        }
        data[j + 1] = curr;
        pm.dataAssign++;

        // incrementaion and loop conditional
        pm.loopAssign++; // i++
        pm.loopComp++;   // i < data.size()
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    return duration.count() / (double)1e9;
}
