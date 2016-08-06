/*************************************************************************
// CST 420 - assignment #3				Name: Patrick J Carlson
//
// File: RiderData.cpp
//
// Source file for the RiderData class. The RiderData class takes in a
// filename with rider information and parses it into appropiate data
// structures. 
//
// It also provides accessor functions to the data within the object.
//
*************************************************************************/

#include "RiderData.h"

//
// Default constructor
//
RiderData::RiderData()
{
}

//
// Returns name of RiderData object.
//
std::string RiderData::getRiderName() const
{
	return m_lastName;
}

//
// Returns team of RiderData object.
//
std::string RiderData::getRiderTeam() const
{	
	return m_teamName;
}

//
// Returns country of RiderData Object.
//
std::string RiderData::getRiderCountry() const
{
	return m_countryName;
}

//
// Returns stage time for requested stage.
//
unsigned RiderData::getStageTime(const unsigned & stage) const
{
	return stageTimes[stage - 1];
}

//
// Returns accumulated stage times for all stages of this rider.
// 
unsigned RiderData::getTotalTime() const
{
	return std::accumulate(stageTimes.begin(), stageTimes.end(), 0);
}

//
// operator overload for input stream of riderData object.
//
std::istream & operator>>(std::istream & input, RiderData & rhs)
{
	input >> rhs.m_lastName >> rhs.m_countryName >> rhs.m_teamName;
	rhs.stageTimes.clear();

	std::string inTimes;

	std::getline(input, inTimes);

	std::stringstream timeStream(inTimes);

	UnsignedInIter unsignedIter(timeStream);

	std::copy(unsignedIter, UnsignedInIter(), std::back_inserter(rhs.stageTimes));

	return input;

}

//
// Less than operator overload for sorting and storing in
// sorted containers.
//
bool operator<(const RiderData & lhs, const RiderData & rhs)
{
	return lhs.m_lastName < rhs.m_lastName;
}
