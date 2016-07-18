#include "Indexer.h"

///
/// Two argument constructor for Indexer object
///
Indexer::Indexer(std::string filename, std::string skipFileName)
	:wordsToSkip(skipFileName), inFileName(filename), skipwordFileName(skipFileName)
{
	parseFile();
	return;
}

///
/// Print function for an Indexer object.
///
void Indexer::printIndexer() const
{
	std::cout << wordIndex << std::endl;
}

///
/// Parsing function for creation of Indexer object. Takes words from file to index
/// and strips them of punctuation, converts all chars to lower case, then compares
/// with strings in skip file. It will finally store those that apply to these 
/// guidelines, including their page number and line number.
void Indexer::parseFile()
{
	std::ifstream inFile;
	std::string inputLine;

	inFile.open(inFileName);
	
	if (!inFile.is_open())
	{
		std::cout << "No index file present with that name." << std::endl;
		system("PAUSE");
		exit(0);

	}

	while (!inFile.eof()) 
	{
		std::getline(inFile, inputLine);

		std::istringstream stringParse(inputLine);

		incLineNmbr();
		while (!stringParse.eof())
		{
			std::string token;

			stringParse >> token;
			if (token == "")
				continue;

			if (token == "<newpage>")
			{
				incPageNmbr();
				lineNmbr = 0;

				break;
			}
			punctStrip(token);

			lowerCase(token);

			if (!wordsToSkip.skipWordcheck(token))
				continue;

			addToIndex(token);
		}
		
	}

	
}

///
/// Removes punctuation from the beginning and ending of a string.
/// Can handle consecutive punction, but not punction within the string.
///
void Indexer::punctStrip(std::string & inString)
{
	while (PUNCTUATIONS.find(*inString.begin()) != PUNCTUATIONS.end())
	{
		inString.erase(inString.begin());
	}

	while (PUNCTUATIONS.find(*inString.rbegin()) != PUNCTUATIONS.end())
	{
		inString.pop_back();
	}
}

///
/// Converts all chars to lower case
///
void Indexer::lowerCase(std::string & inString)
{
	stringIter iter = inString.begin();
	for (; iter != inString.end(); ++iter)
	{
		*iter = tolower(*iter);
	}
	
}

///
/// Adds strings and locations to index.
///
void Indexer::addToIndex(const std::string inString)
{
	wordIndex.addword(inString, lineNmbr, pageNmbr);
}

///
/// Increments current page number(This operation probably did
/// not need to be it's own function).
///
void Indexer::incPageNmbr()
{
	pageNmbr++;
	return;
}

///
/// Decrements current page number(This operation probably did
/// not need to be it's own function).
///
void Indexer::incLineNmbr()
{
	lineNmbr++;
	return;
}
