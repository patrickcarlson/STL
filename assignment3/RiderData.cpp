#include "RiderData.h"


RiderData::RiderData(const std::string & riderFileName)
{
}

std::istream & operator>>(std::istream & input, RiderData & rhs)
{
	input >> rhs.m_lastName >> rhs.m_countryName >> rhs.m_teamName;

	StringInIter inputIter(input);

	std::transform(inputIter, StringInIter(), std::back_inserter(rhs.stageTimes), [](StringInIter& inputIter) {std::stod(*inputIter); });
}
