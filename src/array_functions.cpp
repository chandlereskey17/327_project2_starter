/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
#include <iostream>
#include <sstream>
#include <fstream>
#include <array>
#include "array_functions.h"
#include "constants.h"
#include "utilities.h"
using namespace std;
const int not_finished = -1;
//============================================================================

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct entry {
	string word;
	int number_occurences;
};
//TODO add a global array of entry structs (global to this file)
entry g_array[3000];
//TODO add variable to keep track of next available slot in array

//TODO define all functions in header file

//zero out array that tracks words and their occurrences
void clearArray(){

}

//how many unique words are in array
int getArraySize(){
	return not_finished;
}

//get data at a particular location
string getArrayWordAt(int i){
	std::string not_finished = "Not Finished";
	return not_finished;
}
int getArrayWord_NumbOccur_At(int i){
	return not_finished;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(fstream &myfstream){
	if (!myfstream.is_open()) {return false;}
	string line;
	while (getline(myfstream, line)) {
		processLine(line);
	}
	return true;

}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(string &myString){
	for (int i = 0; i < myString; i++) {

	}
	processToken()
}

/*Keep track of how many times each token seen*/
void processToken(string &token){

}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(fstream& myfile, const string& myFileName,
		ios_base::openmode){
	myfile.open (myFileName);
	if (!myfile.is_open()) {return false;}
	return true;

}

/*iff myfile is open then close it*/
void closeFile(fstream& myfile){
	myfile.close();
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const string &outputfilename){
	return not_finished;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){

}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!


