/*******************************************************************
* Filename: Index.h			Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Index.h is the header file for the Index object. The 
* Index object contains a set container(map would have been better)
* of Word objects. It is used to store information about the location
* of different words within a text file.
*
********************************************************************/

#pragma once

#include "Word.h"
#include <set>
#include <map>
#include <iterator>
#include <iostream>

typedef std::set<Word> wordset;
typedef std::set<Word>::iterator wordsetIter;
typedef std::ostream_iterator<Word> wordOstreamIter;

class Index
{
public:
	Index();
	void addword(std::string inputString, int line, int page);
	friend std::ostream& operator<<(std::ostream& os, const Index oIndex);

private:
	void updateword(Word inputWord, int line, int page);
	wordset storeWords;
};

