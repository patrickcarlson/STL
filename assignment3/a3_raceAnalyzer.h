
/*************************************************************************
// CST 407 - assignment #3				Name: Patrick J Carlson
//
// File: raceAnalyzer.h
//
// Declaration for RaceAnalyzer class.
*************************************************************************/


#ifndef  raceAnalyzer_H
#define  raceAnalyzer_H


#include  <string>
#include  <list>
#include  <set>
#include "StageLength.h"
#include "RiderData.h"

using  namespace  std;


//
// Type definition that can be used to represent a seconds
// time value.
//
typedef  unsigned int  Seconds;
typedef istream_iterator<RiderData> riderInStream;


//
// Declaration
//
class RaceAnalyzer
{
  public  :

    //
    // Do NOT make any modifications to the public interfaces of
    // this class. You can make modifications to this section to
    // provide inline implementations, but do not alter member
    // function signatures.
    //

    //
    // Types
    //

    enum  { fileOpenFailure_ };
      //
      // Exception value thrown when a file open fails.
      //

    typedef  set<string>  StrSet;
      //
      // Used to return a set of rider names, team names, or
      // country names.
      //

    typedef  pair<Seconds, string>  PairResults;
    typedef  list<PairResults>      Results;
      //
      // Used to return stage or race time information for
      // riders.
      //

    typedef  double  MPH;
      //
      // Used to represent a values in miles-per-hour.
      //


    //
    // Member functions
    //

    RaceAnalyzer( const string  &stageFilename,
                  const string  &riderFilename );


    size_t  numStages()  const;
      //
      // Returns the number of stages in the race.
      //


    string  getTeam( const  string  &riderName )  const;
      //
      // Returns the team name for a specified rider.
      //


    string  getCountry( const string  &riderName )  const;
      //
      // Returns the country name for a specified rider.
      //


    StrSet  riders()  const;
      //
      // Returns the names of all the riders in the race.
      //


    StrSet  teams()  const;
      //
      // Returns the names of all the teams in the race.
      //


    StrSet  countries()  const;
      //
      // Returns the names of all the countries represented
      // in the race.
      //


    Results  riderResults( unsigned       stage,
                           const string  &team,
                           const string  &country )  const;
      //
      // Returns riders and stage/race times based on the
      // criteria specified by the parameters.
      //


    Seconds  teamTime( const string  &teamName,
                       unsigned       stage,
                       unsigned       numRiders )  const;
      //
      // Returns stage/race time for the specified team/stage. A
      // team time for a stage is sum of the numRiders fastest
      // times for the team.
      //


    MPH  calcMPH( Seconds  seconds, unsigned  stage )  const;
      //
      // Converts the time for a stace/race into miles-per-hour.
      //


  private  :

	  StageLength m_stageLengths;		//StageLength object contains a list of stage distances
	  std::set<RiderData> m_riders;		// Set of Riders, and their stage times.

};


#endif
