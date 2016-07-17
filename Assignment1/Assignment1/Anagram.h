/*******************************************************************
* Filename: Anagram.h			Author: Patrick J Carlson
* Date Created: 06/25/2016		Last Modified: 07/02/2016
*
* Purpose: Anagram.h is the header file for the Anagram class.
* The anagram class takes in a string to test for anagrams, a 
* string for the title of the dictionary, and then produces a 
* vector containing strings for each anagram of the entered word.
*
********************************************************************/

#pragma once
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>

class Anagram
{
public:
	Anagram(const std::string input, const std::string dictName);
	void print() const;
	std::string noDict = "No dictionary with that name is present.";		//strings for thrown exceptions
	std::string noWord = "There is no word by that name in the dictionary.";//strings for thrown exceptions

private:
	typedef std::vector<std::string>::const_iterator stringVecIter;
	typedef std::vector<std::string> stringVec;
	typedef std::list<std::string>::iterator stringListIter;
	typedef std::list<std::string> stringList;
	int inLength;
	int wordSum = 0;
	std::string inWord;
	stringList dictionary;
	stringVec anagramList;
	void createDictionary(const std::string dictName);
	void createAnagramList();


};

