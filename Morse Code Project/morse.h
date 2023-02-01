#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

void initConversion();

void printResults(const string &inputFile, const string &outputFile, int numLetters);

int convertToMorse(const string &inputFile, const string &outputFile);

int convertToEnglish(const string &inputFile, const string &outputFile);
