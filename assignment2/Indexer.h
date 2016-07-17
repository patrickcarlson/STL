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
	

private:
	void parseFile();
	void punctStrip(std::string& inString);
	void lowerCase(std::string& inString);
	void addToIndex(const std::string inString);
	void incPageNmbr();	// necessary?
	void incLineNmbr();	// necessary?
	std::string inFileName;
	std::string skipwordFileName;
	SkipWords wordsToSkip;
	Index wordIndex;
	int pageNmbr = 1;
	int lineNmbr = 0;
	
};

