/*
 Name: Alexander Potra
 Class: CPSC 122, Spring 2023
 Date: January 31, 2023
 Programming Assignment: PA1                                                                      
 Description: This file declares conversion functions.
*/

#ifndef MORSE_H
#define MORSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

/*************************************************************
 * Function: initConversion ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function initializes the internal array.                    	
 * Input parameters: None    	
 * Returns: None           	      
 *************************************************************/
void initConversion();

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
void printResults(const string &inputFile, const string &outputFile, int numLetters);

/*************************************************************
 * Function: convertToMorse ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function converts English text to Morse 
 *              code.                    	
 * Input parameters: input file, output file    	
 * Returns: number of characters converted           	      
 *************************************************************/
int convertToMorse(const string &inputFile, const string &outputFile);

/*************************************************************
 * Function: convertToEnglish ()                  	
 * Date Created: 1/30/23                  	        
 * Date Last Modified: 1/31/23                        
 * Description: This function converts Morse code to English
 *              text.                    	
 * Input parameters: input file, output file    	
 * Returns: number of characters converted           	      
 *************************************************************/
int convertToEnglish(const string &inputFile, const string &outputFile);

#endif