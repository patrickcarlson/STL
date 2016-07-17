/*******************************************************************
* Filename: Anagram.cpp			Author: Patrick J Carlson
* Date Created: 06/25/2016		Last Modified: 07/02/2016
*
* Purpose: Anagram.h is the source file for the Anagram class.
* The anagram class takes in a string to test for anagrams, a
* string for the title of the dictionary, and then produces a
* vector containing strings for each anagram of the entered word.
*
********************************************************************/

#include "Anagram.h"

///
/// Two argument constructor takes in the string which will be examined
/// for anagrams, and the dictionary from which to compare for anagrams.
/// Results in a vector of strings containing the anagrams of the input
/// string.
/// 
Anagram::Anagram(std::string input, std::string dictionary)
	:inWord(input)
{
	inLength = inWord.length();
	
	createDictionary(dictionary);	

	createAnagramList();

}

///
/// Prints out the list of anagrams, delimited by commas.
///
void Anagram::print() const
{
	stringVecIter iter = anagramList.begin();
	if (iter == anagramList.end())
	{
		std::cout << "There are no anagrams for " << inWord << " in this dictionary." << std::endl;
	}
	else
	{
		std::cout << "There are " << anagramList.size() << " anagrams for " << inWord <<
			" in this dictionary." << std::endl;

		std::cout << "They are: ";

		std::cout << *iter;
		++iter;

		for (; iter != anagramList.end(); )
		{
			std::cout << ", " << *iter;

			++iter;
		}
	}
}



///
/// CreateDictionary takes in the name of the provided dictionary and 
/// includes only those entries which have the same number of characters
/// as the provided word. It then takes of sum of each string, and
/// compares that to the sum of the provided word, and removes those 
/// which do not not match. This provides a smaller dictionary from which
/// to calculate the anagrams for.
///
void Anagram::createDictionary(const std::string dictName)
{

	std::ifstream dictFile;	
	std::string inString;

	dictFile.open(dictName);

	if (!dictFile.is_open())
		throw noDict;

	bool wordPresent = false;

	while (!dictFile.eof())
	{
		dictFile >> inString;
		if (inString.length() == inLength)
			dictionary.push_back(inString);

		if (inString == inWord)
			wordPresent = true;
	}

	if (!wordPresent)
		throw noWord;

	for (int i = 0; i < inLength; ++i)
	{
		wordSum += inWord[i];
	}

	stringListIter iter = dictionary.begin();

	for ( ; iter != dictionary.end(); )
	{
		int thisSum = 0;

		std::string sumString = *iter;

		for (int i = 0; i < inLength; ++i)
		{
			thisSum += sumString[i];
		}

		if (thisSum != wordSum)
		{
			iter = dictionary.erase(iter);
		}
		else
			++iter;
	}
}

///
/// createAnagramList takes in the pared down dictionary, sorts the
/// provided string, and compares to each string in the dictionary
/// (also sorted). All sorted strings from the dictionary, which match
/// the provided string(sorted) are stored in a vector.
///
void Anagram::createAnagramList()
{
	std::string sortedWord = inWord;

	std::sort(sortedWord.begin(), sortedWord.end());

	std::string tempSorted;

	stringListIter iter = dictionary.begin();

	for ( ; iter != dictionary.end(); ++iter)
	{
		tempSorted = *iter;

		std::sort(tempSorted.begin(), tempSorted.end());

		if (tempSorted == sortedWord && inWord != *iter)
		{
			anagramList.push_back(*iter);
		}
	}
}
