#pragma once

#include "Word.h"
#include <set>
#include <map>

typedef std::set<Word> wordset;
typedef std::set<Word>::iterator wordsetIter;
class Index
{
public:
	Index();
	void addword(std::string inputString, int line, int page);

private:
	void updateword(Word inputWord, int line, int page);
	wordset storeWords;
};

