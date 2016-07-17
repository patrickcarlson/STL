#include "Index.h"


Index::Index()
{
}

void Index::addword(std::string inputString, int line, int page)
{
	Word inputWord(inputString);
	inputWord.addLocations(line, page);
	auto check = storeWords.insert(inputWord);
	if (!check.second)
	{
		updateword(inputWord, line, page);
	}

}

void Index::updateword(Word inputWord, int line, int page)
{
	wordsetIter wordIter = storeWords.find(inputWord);
	Word newWord = *wordIter;
	newWord.addLocations(line, page);
	storeWords.erase(inputWord);
	storeWords.insert(newWord);
}
