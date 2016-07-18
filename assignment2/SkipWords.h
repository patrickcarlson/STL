#pragma once

#include <set>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

typedef std::set<std::string> stringSet;
typedef const stringSet::iterator stringSetIter;
typedef std::istream_iterator<std::string> stringInStream;

class SkipWords
{
public:
	SkipWords(std::string skipName);
	bool skipWordcheck(const std::string toCheck) const;

private:
	stringSet skipSet;
};

