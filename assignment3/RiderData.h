#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cstdio>

typedef std::istream_iterator<double> DoubleInIter;
typedef std::istream_iterator<std::string> StringInIter;
typedef std::vector<double> DoubleVec;

class RiderData
{
	
public:
	RiderData(/*const std::string& riderFileName*/);  // Will need riderFileName at some point.
	std::string getRiderTeam() const;
	friend std::istream &operator>>(std::istream& input, RiderData &rhs);
	friend bool operator<(const RiderData& lhs, const RiderData& rhs);		/// This friend not allowed....extern

private:
	std::string riderFile;
	std::string m_lastName;
	std::string m_teamName;
	std::string m_countryName;
	DoubleVec stageTimes;

};

