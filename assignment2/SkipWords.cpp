#include "SkipWords.h"


///
/// Single argument constructor for a skipword object
/// Parses a file to store words to skip in a set container.
///
SkipWords::SkipWords(std::string skipName)
{
	std::ifstream skipFile;

	skipFile.open(skipName);

	if (!skipFile.is_open())
	{
		std::cout << "No skipword file present with that name." << std::endl;
		system("PAUSE");
		exit(0);

	}

	stringInStream skipIn(skipFile);

	copy(skipIn, stringInStream(), std::inserter(skipSet, skipSet.begin()));
}

///
/// Checks and returns a bool whether a word is also within
/// the set of words to skip.
///
bool SkipWords::skipWordcheck(const std::string toCheck) const
{
	stringSetIter findIter = skipSet.find(toCheck);
	
	if (findIter == skipSet.end())
		return true;

	return false;
}


