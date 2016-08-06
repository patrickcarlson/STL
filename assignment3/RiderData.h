/*************************************************************************
// CST 420 - assignment #3				Name: Patrick J Carlson
//
// File: RiderData.h
//
// Header file for the RiderData class. The RiderData class takes in a 
// filename with rider information and parses it into appropiate data
// structures.
//
*************************************************************************/

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <numeric>

typedef std::istream_iterator<unsigned> UnsignedInIter;
typedef std::istream_iterator<std::string> StringInIter;
typedef std::vector<double> UnsignedVec;

class RiderData
{
	
public:
	RiderData();
	std::string getRiderName() const;
	std::string getRiderTeam() const;
	std::string getRiderCountry() const;
	unsigned getStageTime(const unsigned& stage) const;
	unsigned getTotalTime() const;
	friend std::istream &operator>>(std::istream& input, RiderData &rhs);
	friend bool operator<(const RiderData& lhs, const RiderData& rhs);		// This friend not allowed?....extern?

private:
	std::string riderFile;
	std::string m_lastName;
	std::string m_teamName;
	std::string m_countryName;
	UnsignedVec stageTimes;

};

