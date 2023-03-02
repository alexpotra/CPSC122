/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: February 7, 2023
 Programming Assignment: PA2
 Description: This program tests 3 sorting algorithms (selection, optimized bubble,
              and insertion) on 3 vector types (sorted, descending, and random) of
              various sizes and outputs the performance metrics.
*/

#include "sort.h"

typedef vector<int> (*makeVectorFunction)(size_t);
typedef double (*algFunction)(vector<int> &, PerformanceMetrics &);

/*************************************************************
 * Function: makeFile ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function opens and checks the output
 *              file.
 * Input parameters: Name of algorithm
 * Returns: An output file.
 *************************************************************/
ofstream makeFile(string algorithm)
{
    // set up & check output file
    ofstream output;
    output.open(algorithm + "_sort_results.csv");
    if (!output.is_open())
    {
        cout << "Output file failed to open" << endl;
        exit(-1);
    }
    output << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;

    return output;
}

/*************************************************************
 * Function: testCombination ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function outputs the performance metrics
 *              of the given algorithm to the output file.
 * Input parameters: Output file, type of vector, data vector,
 *                   sorting algorithm.
 * Returns: None
 *************************************************************/
void testCombination(ofstream &output, string vectorType, vector<int> v, algFunction alg)
{
    PerformanceMetrics pm;
    double dur = alg(v, pm);
    output << vectorType << " N=" << v.size() << ", " << dur << ", " << pm.dataComp << ", " << pm.loopComp << ", " << pm.dataAssign << ", " << pm.loopAssign << ", " << pm.otherOps << ", " << pm.total() << endl;
}

/*************************************************************
 * Function: runCombinations ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function runs the sorting algorithm on
 *              all given vector sizes.
 * Input parameters: Output file, type of vector, data vector,
 *                   sorting algorithm.
 * Returns: None
 *************************************************************/
void runCombinations(ofstream &output, string vectorType, vector<vector<int>> inputs, algFunction alg)
{
    for (auto &v : inputs)
    {
        testCombination(output, vectorType, v, alg);
    }
}

/*************************************************************
 * Function: main ()
 * Date Created: 2/5/23
 * Date Last Modified: 2/7/23
 * Description: This function executes the program.
 * Input parameters: None
 * Returns: Integer
 *************************************************************/
int main()
{
    // opening write files
    ofstream selectionOutput = makeFile("selection");
    ofstream bubbleOutput = makeFile("bubble");
    ofstream insertionOutput = makeFile("insertion");

    // creating and setting up vectors
    vector<vector<int>> ascVectors = {
        makeAscendingVector(500),
        makeAscendingVector(1000),
        makeAscendingVector(5000),
        makeAscendingVector(10000),
    };

    vector<vector<int>> desVectors = {
        makeDescendingVector(500),
        makeDescendingVector(1000),
        makeDescendingVector(5000),
        makeDescendingVector(10000),
    };

    vector<vector<int>> randVectors = {
        makeRandomVector(500),
        makeRandomVector(1000),
        makeRandomVector(5000),
        makeRandomVector(10000),
    };

    // SELECTION SORT
    runCombinations(selectionOutput, "Sorted", ascVectors, selectionSort);
    runCombinations(selectionOutput, "Descending sorted", desVectors, selectionSort);
    runCombinations(selectionOutput, "Random", randVectors, selectionSort);

    // EARLY EXIT BUBBLE SORT
    runCombinations(bubbleOutput, "Sorted", ascVectors, optimizedBubbleSort);
    runCombinations(bubbleOutput, "Descending sorted", desVectors, optimizedBubbleSort);
    runCombinations(bubbleOutput, "Random", randVectors, optimizedBubbleSort);

    // INSERTION SORT
    runCombinations(insertionOutput, "Sorted", ascVectors, insertionSort);
    runCombinations(insertionOutput, "Descending sorted", desVectors, insertionSort);
    runCombinations(insertionOutput, "Random", randVectors, insertionSort);

    // closing files
    selectionOutput.close();
    bubbleOutput.close();
    insertionOutput.close();

    return 0;
}