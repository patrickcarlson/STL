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

