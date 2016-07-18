/*******************************************************************
* Filename: Indexer.h				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Indexer.cpp is the source file for assignment 2 of CST
* 420, Summer term 2016. Indexer.cpp will  parse the document file
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

