#include "StageLength.h"




StageLength::StageLength(const std::string & stageFilename)
	: stageFile(stageFilename)
{
	std::ifstream inputStream(stageFile); //TODO(Patrick): Error checking(throw exception)

	DoubleIstreamIter InputIter(inputStream);

	std::copy(InputIter, DoubleIstreamIter(), std::back_inserter(stageList));

	numStages = stageList.size();

	totalLength = std::accumulate(stageList.begin(), stageList.end(), 0);
}

double StageLength::getDistance(const int& stageNumber) const
{
	double stageDistance = stageList[stageNumber - 1];
	
	return stageDistance;
}



