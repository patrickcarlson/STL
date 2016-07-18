
/*******************************************************************
* Filename: source.cpp				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: source.cpp contains the main function for the indexer
* operation. Source will prompt the user for file names for the
* text to be indexed, and the skip file to aid in indexing the
* text.
*
* Indexer is not case sensitive.
*
********************************************************************/
#include <string>
#include "Indexer.h"

int main()
{
	std::string fileToIndex;
	std::string wordsToSkip;

	std::cout << "Please enter the name of the file to index: ";
	std::cin >> fileToIndex;

	std::cout << "Please enter the name of the file containing words to skip: ";
	std::cin >> wordsToSkip;

	Indexer indexThis(fileToIndex, wordsToSkip);

	std::cout << std::endl;

	indexThis.printIndexer();

	return 0;
}
