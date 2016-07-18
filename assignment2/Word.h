/*******************************************************************
* Filename: Word.h				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Word.h is the header file for the Word object. The word 
* objects purpose is to hold a string, and a vector of locations
* where that string occurs in the provided text file.
*
********************************************************************/

#pragma once

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include "Locations.h"

typedef std::ostream_iterator<Locations> locOStreamiter;
typedef std::vector<Locations> locationsVec;

class Word
{
public:
	Word(std::string inputWord);
	void addLocations(int line, int page);
	bool operator < (const Word& rhs) const;
	std::string getString() const { return thisWord; }

	friend std::ostream& operator<<(std::ostream& os, const Word& oWord);

private:
	std::string thisWord;
	locationsVec locVec;
};

