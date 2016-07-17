#include "Indexer.h"


Indexer::Indexer(std::string filename, std::string skipFileName)
	:wordsToSkip(skipFileName), inFileName(filename), skipwordFileName(skipFileName)
{
	parseFile();
	return;
}

void Indexer::parseFile()
{
	std::ifstream inFile;
	std::string inputLine;

	inFile.open(inFileName);
	//todo(Patrick): File open error check, assert
	while (!inFile.eof()) {
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

void Indexer::lowerCase(std::string & inString)
{
	stringIter iter = inString.begin();
	for (; iter != inString.end(); ++iter)
	{
		*iter = tolower(*iter);
	}
	
}


void Indexer::addToIndex(const std::string inString)
{
	wordIndex.addword(inString, lineNmbr, pageNmbr);
}

void Indexer::incPageNmbr()
{
	pageNmbr++;
	return;
}

void Indexer::incLineNmbr()
{
	lineNmbr++;
	return;
}
