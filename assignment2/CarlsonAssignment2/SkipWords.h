/*******************************************************************
* Filename: SkipWords.h				Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: SkipWords.h is the header file for the SkipWords object.
* SkipWords.cpp will  parse the skip words text file and store
* the strings whithin in a set container. 
*
********************************************************************/
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

