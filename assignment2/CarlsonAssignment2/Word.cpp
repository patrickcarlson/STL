/*******************************************************************
* Filename: Word.cpp				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Word.cpp is the source file for the Word object. The word
* objects purpose is to hold a string, and a vector of locations
* where that string occurs in the provided text file.
*
********************************************************************/
#include "Word.h"

///
/// Single argument constructor. Stores string into
/// private member.
///
Word::Word(std::string inputWord)
	:thisWord(inputWord)
{
}

///
/// addLocations stores line and page numbers of string
/// location to location vector.
///
void Word::addLocations(int line, int page)
{
	locVec.push_back(Locations(line, page));
}

///
/// Less than operator overload for comparisons once
/// the word object is stored in a container with other
/// word objects.
///
bool Word::operator<(const Word & rhs) const
{
	return thisWord < rhs.thisWord;
}

///
/// Ostream operator overload. Utilized ostream_iterator to 
/// output vector of locations.
///
std::ostream& operator<<(std::ostream& os, const Word& oWord)
{
	os  << oWord.getString() << std::endl << "  ";
	locOStreamiter outIter(os, ", ");

	std::copy(oWord.locVec.begin(), oWord.locVec.end(), outIter);


	os << "\b" << "\b" <<" " << " ";	// Utilized to remove comma at end of stream.

	return os;

}