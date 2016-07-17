/*******************************************************************
* Filename: Indexer.cpp				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/14/2016
*
* Purpose: Indexer.cpp is the source file for assignment 2 of CST
* 420, Summer term 2016. Indexer.cpp's purpose is to prompt a user
* for the input of two file names. The two files are a document file
* and a skip word file. Indexer.cpp will then parse the document file
* and output those words which are not in the skip file. Each word, 
* when output, will also display what lines, and what pages it appears
* on, in the following format.
* 
* word
*   pg#.ln#
* 
* Indexer is not case sensitive.
*
********************************************************************/
#include <string>

/// for testing
#include "Indexer.h"
#include <utility>
/// for testing

//parse(std::string document, std::string skiplist);
void Lowercase(std::string& input);
int main()
{
	Indexer something("a2_doc1.txt", "a2_skip1.txt");

	return 0;
}
///
/// Lowercase converts a provided string to all lowercase letters.
///
void Lowercase(std::string & input)
{
	for (std::string::iterator iter = input.begin(); iter != input.end(); ++iter)
	{
		*iter = tolower(*iter);
	}
}
