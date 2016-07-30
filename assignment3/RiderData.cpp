#include "RiderData.h"


RiderData::RiderData(/*const std::string & riderFileName*/)
	/*:riderFile(riderFileName)*/
{





}

std::string RiderData::getRiderTeam() const
{	
	return m_teamName;
}

std::istream & operator>>(std::istream & input, RiderData & rhs)
{
	input >> rhs.m_lastName >> rhs.m_countryName >> rhs.m_teamName;
	
	std::string inTimes;

	std::getline(input, inTimes);

	std::stringstream timeStream(inTimes);

	DoubleInIter doubleIter(timeStream);

	std::copy(doubleIter, DoubleInIter(), std::back_inserter(rhs.stageTimes));

	return input;

}

bool operator<(const RiderData & lhs, const RiderData & rhs)
{
	return lhs.m_lastName < rhs.m_lastName;
}
