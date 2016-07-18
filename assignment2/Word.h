#pragma once

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include "Locations.h"

typedef std::ostream_iterator<Locations> locOStreamiter;
typedef std::vector<Locations> locationsVec;
class Word
{
public:
	Word(std::string inputWord);
	void addLocations(int line, int page);
	bool operator < (const Word& rhs) const;
	std::string getString() const { return thisWord; }

	friend std::ostream& operator<<(std::ostream& os, const Word& oWord);

private:
	std::string thisWord;
	locationsVec locVec;
};

