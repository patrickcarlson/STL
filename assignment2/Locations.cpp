/*******************************************************************
* Filename: Locations.h			Author: Patrick J Carlson
* Date Created: 07/14/2016		Last Modified: 07/14/2016
*
* Purpose: Locations.cpp contains the member functions for the
* Locations class. The Locations class contains a pair which
* stores two ints. These two ints represent the line and page
* number of the word locations.
*
********************************************************************/
#include "Locations.h"

///
/// Locations(int line, int page) is a two argument constructor the 
/// the Locations class. It takes in two ints, and assigns them to
/// pair member variable linesPages.
///
Locations::Locations(int line, int page)
{
	linesPages.first = line;

	linesPages.second = page;
}


/// 
/// int Locations::GetLine() const is a public member funtion which returns 
/// the integer stored in the first location of the pair.
///
int Locations::GetLine() const
{
	return linesPages.first;

}

/// 
/// int Locations::GetPage() const is a public member funtion which returns 
/// the integer stored in the Second location of the pair.
///
int Locations::GetPage() const
{
	return linesPages.second;
}


