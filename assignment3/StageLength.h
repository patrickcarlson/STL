#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

typedef std::istream_iterator<double> DoubleIstreamIter;
typedef std::vector<double> DoubleVec;

class StageLength
{



public:
	StageLength(const std::string& stageFilename);
	double getDistance(const int& stageNumber) const;
	unsigned int getNumStages() const;

private:

	void addStage() { ++numStages; } //TODO(Patrick): Is this necessary, unused at this point.
	std::string stageFile;
	DoubleVec stageList;
	int numStages;
	double totalLength;

};

