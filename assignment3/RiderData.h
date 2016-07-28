#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

typedef std::istream_iterator<std::string> StringInIter;
typedef std::vector<double> DoubleVec;

class RiderData
{
	friend std::istream &operator>>(std::istream& input, RiderData &rhs);
public:
	RiderData(const std::string& riderFileName);

private:
	std::string m_lastName;
	std::string m_teamName;
	std::string m_countryName;
	DoubleVec stageTimes;

};

