#include "RiderData.h"


RiderData::RiderData(/*const std::string & riderFileName*/)
	/*:riderFile(riderFileName)*/
{





}

std::string RiderData::getRiderName() const
{
	return m_lastName;
}

std::string RiderData::getRiderTeam() const
{	
	return m_teamName;
}

std::string RiderData::getRiderCountry() const
{
	return m_countryName;
}

unsigned RiderData::getStageTime(const unsigned & stage) const
{
	return stageTimes[stage - 1];
}

unsigned RiderData::getTotalTime() const
{
	return std::accumulate(stageTimes.begin(), stageTimes.end(), 0);
}

std::vector<unsigned int> RiderData::getVectorofTimes() const
{
	std::vector<unsigned int> timeVec;
	std::copy(stageTimes.begin(), stageTimes.end(), std::back_inserter(timeVec));
	return timeVec;
}

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

bool operator<(const RiderData & lhs, const RiderData & rhs)
{
	return lhs.m_lastName < rhs.m_lastName;
}
