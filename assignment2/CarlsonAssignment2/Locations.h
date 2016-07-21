/*******************************************************************
* Filename: Locations.h			Author: Patrick J Carlson
* Date Created: 07/07/2016		Last Modified: 07/17/2016
*
* Purpose: Locations.h is the header file for the Locations class.
* The Locations class contains a pair, which stores two integers.
* These two integers represent the line and page for where a word
* is discovered.
*
* Member functions:
* Locations(int line, int page): two argument constructor for
*		the Locations class.
* int Getline() const: returns the integer representing the line.
* int GetPage() const: returns the integer representing the page.
*
********************************************************************/
#pragma once

#include <utility>
#include <iostream>

class Locations
{
public:
	Locations(int line, int page);
	int GetLine() const;
	int GetPage() const;

	friend std::ostream& operator << (std::ostream& os, const Locations& loc);

private:
	std::pair<int, int> linesPages; //holds line and page numbers
};

