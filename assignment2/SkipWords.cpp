#include "SkipWords.h"



SkipWords::SkipWords(std::string skipName)
{
	std::ifstream skipFile;

	skipFile.open(skipName);

	stringInStream skipIn(skipFile);

	copy(skipIn, stringInStream(), std::inserter(skipSet, skipSet.begin()));
}

bool SkipWords::skipWordcheck(const std::string toCheck) const
{
	stringSetIter findIter = skipSet.find(toCheck);
	
	if (findIter == skipSet.end())
		return true;

	return false;
}


