/*******************************************************************
* Filename: Indexer.h				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Indexer.h is the header file for the Indexer object. 
* Indexer.cpp will  parse the document file
* and output those words which are not in the skip file. 
*
********************************************************************/

#pragma once

#include "Index.h"
#include "SkipWords.h"
#include <iostream>
#include <sstream>
#include <string>

typedef std::string::iterator stringIter;
typedef std::string::reverse_iterator revStringIter;
const std::set<char> PUNCTUATIONS = { '.', ',', '"', ';', ':', '?', '\'', '(', ')', '!',
									'{', '}', '[', ']', '\\', '/' };

class Indexer
{
public:
	Indexer(std::string filename, std::string skipFileName);
	void printIndexer() const;
	

private:
	void parseFile();
	void punctStrip(std::string& inString);
	void lowerCase(std::string& inString);
	void addToIndex(const std::string inString);
	void incPageNmbr();	
	void incLineNmbr();	
	std::string inFileName;
	std::string skipwordFileName;
	SkipWords wordsToSkip;
	Index wordIndex;
	int pageNmbr = 1;
	int lineNmbr = 0;
	
};

