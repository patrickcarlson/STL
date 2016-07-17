/*******************************************************************
* Filename: Source.cpp				Author: Patrick J Carlson
* Date Created: 06/25/2016		Last Modified: 07/03/2016
*
* Purpose: Source.cpp is the source file for assignment one of 
* CST 420 for summer term of 2016. The purpose of the source file
* is to provide a platform for iteracting with the anagram class
*
********************************************************************/

#include "Anagram.h"
#include <string>
#include <cstdlib>

///
/// Strings match exception output of the anagram class.
///
const std::string NO_DICTIONARY = "No dictionary with that name is present.";
const std::string NO_WORD = "There is no word by that name in the dictionary.";

void dictionaryPrompt(std::string& dictionary);
void wordPrompt(std::string& inputWord);

int main()
{
	std::string dictionary;	
	std::string word;
	int entry;
	bool end = false;
	
	dictionaryPrompt(dictionary);

	while (!end) 
	{
		wordPrompt(word);

		try
		{
			Anagram anagramProc(word, dictionary);
			anagramProc.print();

			std::cout << std::endl << "Enter 1 if you would like to enter another word: " << std::endl;
			std::cin >> entry;

			if (entry != 1)
				end = true;	

			entry = 1;		// Catches situations where a non int was entered.
		}

		catch (std::string& except)
		{
			std::cout << except << std::endl;
			if (except == NO_DICTIONARY)
				dictionaryPrompt(dictionary);

			continue;
		}

		

	}

	return EXIT_SUCCESS;
}

///
/// dictionaryPrompt prompts for and stores the name of the
/// dictionary, via the console.
///
void dictionaryPrompt(std::string& dictionary)
{
	std::cout << "Please enter a dictionary name: ";
	std::cin >> dictionary;
	std::cout << std::endl;
}

///
/// wordPrompt prompts for and stores the word to be 
/// analyzed, via the console.
///
void wordPrompt(std::string& inputWord)
{
	std::cout << "Please enter the word to analyze: ";
	std::cin >> inputWord;
	std::cout << std::endl;
}