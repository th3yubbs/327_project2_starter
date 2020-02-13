/*
 * functionstocomplete.cpp
 *
 *  Created on: Feb. 10th 2020
 *      Author: Alexander Stubbs-Yates
 */

//============================================================================
//	TODO add necessary includes here
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "array_functions.h"
#include "constants.h"
#include "utilities.h"
//============================================================================
using namespace std;
using namespace constants;
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct trackingWords {
	int count;
	string word;
};

//TODO add a global array of entry structs (global to this file)
struct trackingWords wordArray[MAX_WORDS];

//TODO add variable to keep track of next available slot in array
int nextSlot;

//zero out array that tracks words and their occurrences
void clearArray() {
	nextSlot = 0;
}

//how many unique words are in array
int getArraySize() {
	return nextSlot;
}

//get data at a particular location
string getArrayWordAt(int i) {
	return wordArray[i].word;
}

int getArrayWord_NumbOccur_At(int i) {
	return wordArray[i].count;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(fstream &myfstream) {
	string line;
	if (myfstream.is_open()) {
		while (getline(myfstream, line)) {
			processLine(line);
		}
		return true;
	} else {
		return false;
	}

}

/*take 1 line and extract all the tokens from it
 feed each token to processToken for recording*/
void processLine(string &myString) {
	string token;
	stringstream feeder(myString);

	while (getline(feeder, token, CHAR_TO_SEARCH_FOR)) {
		processToken(token);
	}
}

/*Keep track of how many times each token seen*/
void processToken(string &token) {
	string processedToken = token;
	strip_unwanted_chars(token);

	if (token == "") {
		return;
	}

	for (int i = 0; i < nextSlot; i++) {
		string processedWord = wordArray[i].word;
		toUpper(processedToken);
		toUpper(processedWord);

		if (processedToken == processedWord) {
			wordArray[i].count++;
			return;
		}
	}

	wordArray[nextSlot].word = token;
	wordArray[nextSlot].count = 1;
	nextSlot++;
}

/*if you are debugging the file must be in the project parent directory
 in this case Project2 with the .project and .cProject files*/
bool openFile(fstream &myfile, const string &myFileName,
		ios_base::openmode mode) {
	myfile.open(myFileName, mode);

	if (!myfile.is_open()) {
		return false;
	} else {
		return true;
	}
}

/*iff myfile is open then close it*/
void closeFile(fstream &myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const string &outputfilename) {
	ofstream out(outputfilename);
	out.open(outputfilename);


	if (!out.is_open()) {
		return FAIL_FILE_DID_NOT_OPEN;
	} else if (nextSlot == 0) {
		return FAIL_NO_ARRAY_DATA;
	} else {
		return SUCCESS;
	}
}

/*
 * Sort myEntryArray based on so enum value.
 * The presence of the enum implies a switch statement
 */
void sortArray(sortOrder so) {
	switch (so) {
	case 1:
		return;
	case 2:
		return;
	case 3:
		return;
	}
//TODO
}

