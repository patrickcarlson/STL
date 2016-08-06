/*************************************************************************
// CST 420 - assignment #3				Name: Patrick J Carlson
//
// File: StageLength.cpp
//
// Source file for the StageLength class. The StageLength class takes in a
// filename with stage distances and parses that data into appropiate
// containers.
//
*************************************************************************/

#include "StageLength.h"



//
// Single argument constructor the StageLength class.
//
StageLength::StageLength(const std::string & stageFilename)
	: stageFile(stageFilename)
{
	std::ifstream inputStream(stageFile); //TODO(Patrick): Error checking(throw exception)

	if (!inputStream.is_open())
	{
		std::cout << "there is no file with the name " << stageFile << " present." << std::endl;
		throw fileOpenFailure_;
	}
	DoubleIstreamIter InputIter(inputStream);

	std::copy(InputIter, DoubleIstreamIter(), std::back_inserter(stageList));

	numStages = stageList.size();

	totalLength = std::accumulate(stageList.begin(), stageList.end(), 0);
}

//
// Returns the distance of the requested stage.
//
double StageLength::getDistance(const int& stageNumber) const
{
	double stageDistance = stageList[stageNumber - 1];
	
	return stageDistance;
}

//
// Returns total distance of all stages combined.
//
double StageLength::getTotalLength() const
{
	return totalLength;
}

//
// Returns total number of stages.
//
unsigned int StageLength::getNumStages() const
{
	return numStages;
}



