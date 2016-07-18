/*******************************************************************
* Filename: Index.h			Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Index.cpp is the source file for the Index object. The
* Index object contains a set container(map would have been better)
* of Word objects. It is used to store information about the location
* of different words within a text file.
*
********************************************************************/
#include "Index.h"

///
/// Default constructor of Index object.
///
Index::Index()
{
}

///
/// addword function takes a string, and two integers represetning the
/// location of that word in the text file, and adds them to a set as
/// a word object. Map would be preferred here.
///
void Index::addword(std::string inputString, int line, int page)
{
	Word inputWord(inputString);
	inputWord.addLocations(line, page);
	auto check = storeWords.insert(inputWord);
	if (!check.second)
	{
		updateword(inputWord, line, page);
	}

}

///
/// updateword is called when the addword function finds a string
/// which is already stored in the set of Words. This copies, adds
/// new info, deletes old set item, and adds updated item. This is
/// why a map would have been prefered.
///
void Index::updateword(Word inputWord, int line, int page)
{
	wordsetIter wordIter = storeWords.find(inputWord);
	Word newWord = *wordIter;
	newWord.addLocations(line, page);
	storeWords.erase(inputWord);
	storeWords.insert(newWord);
}

///
/// ostream overload. Utilizes ostream_iterators to output
/// set of Words.
std::ostream & operator<<(std::ostream & os, const Index oIndex)
{
	std::cout << "Index" << std::endl << "_____" << std::endl;

	wordOstreamIter outIter(std::cout, "\n");

	std::copy(oIndex.storeWords.begin(), oIndex.storeWords.end(), outIter);
	
	return os;
}
