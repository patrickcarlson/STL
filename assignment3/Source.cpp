#include "a3_raceAnalyzer.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>


int main()
{
	RaceAnalyzer newRace("a3_stages.txt", "a3_riders.txt");
	
	int stages = newRace.numStages();

	string team = newRace.getTeam("Kattson");

	string country = newRace.getCountry("Kattson");

	set<string> riders = newRace.riders();

	set<string> teams = newRace.teams();

	set<string> countries = newRace.countries();

	std::cout << stages << " " << team << " " << country << " " <<  std::endl;

	newRace.riderResults(2, "XYZ", "GER");

	std::cout << newRace.teamTime("XYZ", 0, 3) << std::endl;
	
	/*StageLength newStage("a3_stages.txt");

	std::cout << newStage.getDistance(2) << std::endl;*/
	
	
	/*std::ifstream inFile("a3_riders.txt");


	riderVec riders;

	std::copy(vecInStream(inFile), vecInStream(), std::back_inserter(riders));*/



	return 0;
}