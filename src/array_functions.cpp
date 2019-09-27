/*
 * Name: Chandler Eskey
 *
 *
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
#include "array_functions.h"
#include "constants.h"
#include "utilities.h"
using namespace std;

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
entry g_array[constants::MAX_WORDS];
//TODO add variable to keep track of next available slot in array
int next_slot = 0;
//TODO define all functions in header file

//zero out array that tracks words and their occurrences
void clearArray(){
	next_slot = 0;
}

//how many unique words are in array
int getArraySize(){
	return next_slot;
}

//get data at a particular location
string getArrayWordAt(int i){
		return g_array[i].word;
}
int getArrayWord_NumbOccur_At(int i){
		return g_array[i].number_occurences;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(fstream &myfstream){

	if (!myfstream.is_open()) {return false;}
	string line;
	while (!myfstream.eof()) {
		getline(myfstream, line);
		processLine(line);
	}
	closeFile(myfstream);
	return true;

}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(string &myString){
	stringstream ss(myString);
	string tempToken;
	while(getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)) {
		processToken(tempToken);
	}
}

/*Keep track of how many times each token seen*/
void processToken(string &token){
	if (strip_unwanted_chars(token)){
		for (int i = 0; i < next_slot; i++) {
			string tok = token;
			string g = g_array[i].word;
			toUpper(tok);
			toUpper(g);
			if (tok == g) {
				g_array[i].number_occurences++;
				return;
			}
		}
	entry new_entry;
	g_array[next_slot] = new_entry;
	g_array[next_slot].word = token;
	g_array[next_slot].number_occurences = 1;
	next_slot++;
	}
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(fstream& myfile, const string& myFileName,
		ios_base::openmode mode){
	myfile.open (myFileName.c_str(), mode);
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
	ofstream output;
	output.open(outputfilename.c_str(), fstream::out);
	if (!output.is_open()) {return constants::FAIL_FILE_DID_NOT_OPEN;}
	else if (next_slot == 0) {return constants::FAIL_NO_ARRAY_DATA;}

	for (int i = 0; i < next_slot; i++) {
		output << g_array[i].word << " " << g_array[i].number_occurences << endl;
	}
	output.close();

	return constants::SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	entry holder;

	switch (so) {
		case constants::ASCENDING :{
			bool switch_around = true;
			while (switch_around) {
				switch_around = false;
				for(int i = 0; i < next_slot - 1; i++) {
					string first = g_array[i].word;
					string second = g_array[i + 1].word;
					toUpper(first);
					toUpper(second);
					if (first > second) {
						holder = g_array[i];
						g_array[i] = g_array[i + 1];
						g_array[i + 1] = holder;
						switch_around = true;
					}
				}
			}break;
		}
		case constants::DESCENDING :{
			for (int i = 0; i < next_slot; i++) {
				for(int j = i + 1; i < next_slot; i++) {
					if (g_array[i].word < g_array[j].word) {
						holder = g_array[i];
						g_array[i] = g_array[j];
						g_array[j] = holder;
					}
				}
			}break;
		}
		case constants::NUMBER_OCCURRENCES :{
			for (int i = 0; i < next_slot; i++) {
				for(int j = i + 1; i < next_slot; i++) {
					if (g_array[i].word == g_array[j].word) {
						holder = g_array[i];
						g_array[i] = g_array[j];
						g_array[j] = holder;
					}
				}
			}break;
		}
	}
}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!


