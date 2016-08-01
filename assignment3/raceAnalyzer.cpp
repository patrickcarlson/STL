#include "raceAnalyzer.h"
namespace
{
	///
	/// Predicate Functor returns true if name matches that within
	/// the container.
	///
	struct find_by_name
	{
		find_by_name(const string& ridersName) : m_name(ridersName) {}
		bool operator()(const RiderData& rider)
		{
			return rider.getRiderName() == m_name;
		}

	private:
		string m_name;
	};

	///
	/// Predicate returns true if team name passed in matches rider elements
	/// team name.
	///
	struct is_not_team_name
	{
		is_not_team_name(const string& teamName) : m_team(teamName) { }
		bool operator ()(const RiderData& rider)
		{
			return rider.getRiderTeam() != m_team;
		}

	private:
		string m_team;
	};

	///
	/// Predicate returns true if country name passed in matches rider elements
	/// country name.
	///
	struct is_not_country_name
	{
		is_not_country_name(const string& countryName) : m_country(countryName) {}
		bool operator() (const RiderData& rider)
		{
			return rider.getRiderCountry() != m_country;
		}

	private:
		string m_country;
	};

}

RaceAnalyzer::RaceAnalyzer(const string & stageFilename, const string & riderFilename)
	:m_stageLengths(stageFilename)
{
	ifstream inFile(riderFilename);

	if (!inFile.is_open())
	{
		cout << "There is no file with the name " << riderFilename << " present." << endl;
		throw fileOpenFailure_;
	}

	riderInStream riderInData(inFile);

	copy(riderInData, riderInStream(), inserter(m_riders, m_riders.end()));
}

//
// Returns the number of stages in the race.
//
size_t RaceAnalyzer::numStages() const
{
	return m_stageLengths.getNumStages();
}

//
// Returns the team name for a specified rider.
//
string RaceAnalyzer::getTeam(const string & riderName) const
{
	
	riderSetIter iter = find_if(m_riders.begin(), m_riders.end(), find_by_name(riderName));

	if (iter != m_riders.end())
	{
		return iter->getRiderTeam();
	}
}

//
// Returns the country name for a specified rider
//
string RaceAnalyzer::getCountry(const string & riderName) const
{
	riderSetIter iter = find_if(m_riders.begin(), m_riders.end(), find_by_name(riderName));

	if (iter != m_riders.end())
	{
		return iter->getRiderCountry();
	}
}

//
// Returns the names of all the riders in the race.
//
RaceAnalyzer::StrSet RaceAnalyzer::riders() const
{
	StrSet riderNames;
	transform(m_riders.begin(), 
			m_riders.end(), 
			inserter(riderNames, riderNames.end() ), 
			[](const RiderData& riderIn) {return riderIn.getRiderName(); } );
	
	return riderNames;
}

//
// Returns the names of all the teams in the race.
//
RaceAnalyzer::StrSet RaceAnalyzer::teams() const
{
	StrSet teams;
	transform(m_riders.begin(),
		m_riders.end(),
		inserter(teams, teams.end()),
		[](const RiderData& riderIn) {return riderIn.getRiderTeam(); });

	return teams;
}

//
// Returns the names of all the countries represented
// in the race.
//
RaceAnalyzer::StrSet RaceAnalyzer::countries() const
{
	StrSet countries;
	transform(m_riders.begin(),
		m_riders.end(),
		inserter(countries, countries.end()),
		[](const RiderData& riderIn) {return riderIn.getRiderCountry(); });

	return countries;
}

//
// Returns riders and stage/race times based on the
// criteria specified by the parameters.
//
RaceAnalyzer::Results RaceAnalyzer::riderResults(unsigned stage, const string & team, const string & country) const
{
	Results resultList;

	riderSet resultSet;
	if (team.size() != 0)
	{
		remove_copy_if(m_riders.begin(), m_riders.end(), inserter(resultSet, resultSet.end()), is_not_team_name(team));
	}
	else
	{
		copy(m_riders.begin(), m_riders.end(), inserter(resultSet, resultSet.end()));
	}

	riderSet newSet;

	if (country.size() != 0)
	{
		remove_copy_if(resultSet.begin(), resultSet.end(), inserter(newSet, newSet.end()), is_not_country_name(country));
	}
	else
	{
		copy(resultSet.begin(), resultSet.end(), inserter(newSet, newSet.end()));
	}


	for_each(newSet.begin(), newSet.end(),
		[&resultList, &stage](const RiderData& rider)
	{
		Seconds riderTotal;
		if (stage == 0)
			riderTotal = rider.getTotalTime();
		else
			riderTotal = rider.getStageTime(stage);
		PairResults riderPair;
		riderPair.first = riderTotal;
		riderPair.second = rider.getRiderName();

		resultList.push_back(riderPair);
	});

	return resultList;
}

//
// Returns stage/race time for the specified team/stage. A
// team time for a stage is sum of the numRiders fastest
// times for the team.
//
Seconds RaceAnalyzer::teamTime(const string & teamName, unsigned stage, unsigned numRiders) const
{
	riderSet teamSet;

	vector<Seconds> timeVec;
	remove_copy_if(m_riders.begin(), m_riders.end(), inserter(teamSet, teamSet.end()), is_not_team_name(teamName));
	
	if (stage != 0)
	{
		for_each(teamSet.begin(), teamSet.end(),
			[&timeVec, stage](const RiderData& riders)
			{
				timeVec.push_back(riders.getStageTime(stage));
			});

		sort(timeVec.begin(), timeVec.end());

		
		return accumulate(timeVec.begin(), timeVec.begin() + numRiders, 0);
	}

	else
	{
		Seconds stageSums;
		int stageCount = 1;
		vector<Seconds> stagesVec(m_stageLengths.getNumStages());
		for_each(stagesVec.begin(), stagesVec.end(), 
			[&timeVec, &teamSet, &stageCount, &stagesVec, &numRiders](const Seconds& time) 
		{
			timeVec.clear();

			for_each(teamSet.begin(), teamSet.end(),
				[&timeVec, &stageCount](const RiderData& riders)
			{
				timeVec.push_back(riders.getStageTime(stageCount));
			});

			sort(timeVec.begin(), timeVec.end());

			stagesVec[stageCount - 1] = accumulate(timeVec.begin(), timeVec.begin() + numRiders, 0);

			stageCount++;
		});

		stageSums = accumulate(stagesVec.begin(), stagesVec.end(), 0);

		return stageSums;
	}
}

//
// Converts the time for a stage/race into miles-per-hour.
//
RaceAnalyzer::MPH RaceAnalyzer::calcMPH(Seconds seconds, unsigned stage) const
{
	double length;
	double speed;
	if (stage != 0)
		length = m_stageLengths.getDistance(stage);

	else
		length = m_stageLengths.getTotalLength();

	speed = length / seconds;
	speed *= 3600;
	return speed;

}
