#include "Word.h"


Word::Word(std::string inputWord)
	:thisWord(inputWord)
{
}

void Word::addLocations(int line, int page)
{
	locVec.push_back(Locations(line, page));
}

bool Word::operator<(const Word & rhs) const
{
	return thisWord < rhs.thisWord;
}
