#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#include "Player.h"

#define TEAM_H

class Team {
	public:
		int oppPossessions;
		int oppORB;
		int oppDRB;
		int oppTRB;
		int oppFGA;
		int opp3PA;

		void addPlayer(const myPlayer& player);
		
		void calcSumOfTeamStats();

		void calculateTeamStats();
		void calcTeamAdvStats();
		void calcIndAdvStats();
		void ListAllPlayers();

		double getTeamORB();
		double getTeamDRB();
		double getTeamTRB();
		double getTeamFGM();

		double getTeamTrueShooting();
		double getTeamEffectiveFGPercentage();
		double getTeamORBpercentage();
		double getTeamDRBpercentage();
		double getTeamTRBpercentage();
		double getTeamASTPercentage();
		double getTeamThreePointAttemptRate();
		double getTeamFreeThrowAttemptRate();
		double getTeamStealPercentage();
		double getTeamBlockPercentage();
		double getTeamTurnoverPercentage();
		double getTeamUsagePercentage();

		void setOpponentTeamStatistics(int opponentPossessions, int opponentORB, int opponentDRB, int opponentTRB, int opponentFGA, int opponent3PA);

	private:
		std::vector<myPlayer> playerList;

		struct AdvPlayerStruct
		{
			double TrueShootingPercentage;
			double EffectiveFieldGoalPercentage;
			double ThreePointAttemptRate, FreeThrowAttemptRate;			
			

			double OffensiveReboundPercentage, DeffensiveReboundPercentage, TotalReboundPercentage;
			double AssistPercentage, StealPercentage, BlockPercentage, TurnoverPercentage, UsagePercentage;
		};

		std::vector<AdvPlayerStruct> AdvPlayerValues;

			
		
		int teamMinutesPlayed, teamSecondsPlayed, teamInGameTime;
		double teamFGA, teamFGM, teamFGPercentage;
		double teamThreePM, teamThreePA, teamThreePPercentage;
		double teamFTM, teamFTA, teamFTPercentage;
		int teamOffensiveRB = 0, teamDeffensiveRB = 0, teamTotalRB;
		int teamAST = 0;
		int teamBLK = 0;
		int teamTOV = 0;
		int teamPTS = 0;
		int teamSTL = 0;
		int teamPF = 0;
		int teamplusMinus = 0;

		
		//team 

		double TeamThreePointAttemptRate, TeamFreeThrowAttemptRate;
		double TeamTrueShootingAttempts, TeamTrueShootingPercentage;
		double TeamEffectiveFieldGoalPercentage;
		double TeamOffensiveReboundPercentage, TeamDeffensiveReboundPercentage, TeamTotalReboundPercentage;
		double TeamAssistPercentage;
		double TeamStealPercentage, TeamBlockPercentage, TeamTurnoverPercentage, TeamUsagePercentage;


		//advamced team stats
		/*
		double TeamTrueShootingPercentage;
		double TeamEffectiveFieldGoalPercentage;
		double TeamThreePointAttemptRate, TeamFreeThrowAttemptRate;
		double TeamOffensiveReboundPercentage, TeamDeffensiveReboundPercentage, TeamTotalReboundPercentage;
		double TeamAssistPercentage, TeamStealPercentage, TeamBlockPercentage, TeamTurnoverPercentage, TeamUsagePercentage;
		*/
};