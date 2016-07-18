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

std::ostream& operator<<(std::ostream& os, const Word& oWord)
{
	os  << oWord.getString() << std::endl << "  ";
	locOStreamiter outIter(os, ", ");

	std::copy(oWord.locVec.begin(), oWord.locVec.end(), outIter);

	os << "\b" << "\b" <<" " << " ";

	return os;

}