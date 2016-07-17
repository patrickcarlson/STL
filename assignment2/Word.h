#pragma once

#include <vector>
#include "Locations.h"

typedef std::vector<Locations> locationsVec;
class Word
{
public:
	Word(std::string inputWord);
	void addLocations(int line, int page);
	bool operator < (const Word& rhs) const;

private:
	std::string thisWord;
	locationsVec locVec;
};

