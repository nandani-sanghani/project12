#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


#include "Team.h"

void Team::addPlayer(const myPlayer& player)
{
	this->playerList.push_back(player);
	
}

void Team::calcSumOfTeamStats()
{	
	for (int i = 0; i < this->playerList.size(); i++) {
		this->teamMinutesPlayed += playerList[i].getMinutesPlayed();
		this->teamFGM += playerList[i].getFieldGoalsMade();
		this->teamFGA += playerList[i].getFieldGoalsAttemtped();
		this->teamThreePM += playerList[i].getThreePointersMade();
		this->teamThreePA += playerList[i].getThreePointersAttemtped();
		this->teamFTM += playerList[i].getFreeThrowsMade();
		this->teamFTA += playerList[i].getFreeThrowsAttemtped();
		this->teamOffensiveRB += playerList[i].getORebounds();
		this->teamDeffensiveRB += playerList[i].getDRebounds();

		
		this->teamAST += playerList[i].getAssists();
		this->teamSTL += playerList[i].getSteals();
		this->teamBLK += playerList[i].getBlocks();
		this->teamTOV += playerList[i].getTurnovers();
	}

	this->teamPTS = ((this->teamFGM - this->teamThreePM) * 2) + (this->teamThreePM * 3) + this->teamFTM;
	this->teamTotalRB = this->teamOffensiveRB + this->teamDeffensiveRB;
	
	/*
	* Was used to check if the values were correct
	* 
	cout << "Team minutes played: " << this->teamMinutesPlayed << endl;
	cout << "Team Field Goals made: " << this->teamFGM << endl;
	cout << "Team Field Goals attempted: " << this->teamFGA << endl;
	cout << "Three pointers made: " << this->teamThreePM << endl;
	cout << "Three pointers attempted: " << this->teamThreePA << endl;
	cout << "Free Throws made: " << this->teamFTM << endl;
	cout << "Free Throws attempted: " << this->teamFTA << endl;
	*/
}

void Team::calculateTeamStats()
{
	this->teamInGameTime = this->teamMinutesPlayed / 60;
	this->teamFGPercentage = this->teamFGM / this->teamFGA;
	this->teamThreePPercentage = this->teamThreePM / this->teamThreePA;
	this->teamFTPercentage = this->teamFTM / this->teamFTA;
	/*
	cout << "Team Field Goal Percentage: " << this->teamFGPercentage << endl;
	cout << "Team Three Point Percentage: " << this->teamThreePPercentage << endl;
	cout << "Team Free Throw Percentage: " << this->teamFTPercentage << endl;
	*/
}

void Team::calcTeamAdvStats()
{
	TeamTrueShootingPercentage = (this->teamPTS / (2 * (this->teamFTA * 0.44 + this->teamFGA)));
	TeamEffectiveFieldGoalPercentage = ((this->teamFGM + 0.5 * this->teamThreePM) / this->teamFGA) * 1000;
	TeamThreePointAttemptRate = (this->teamThreePA / this->teamFGA) * 1000;
	TeamFreeThrowAttemptRate = (this->teamFTA / this->teamFGA) * 1000;

	TeamOffensiveReboundPercentage = (100 * (this->teamOffensiveRB * static_cast<double>(2880))) / (static_cast<double>(2880) * (this->teamOffensiveRB + this->oppDRB));
	TeamDeffensiveReboundPercentage = (100 * (this->teamDeffensiveRB * static_cast<double>(2880))) / (static_cast<double>(2880) * (this->teamDeffensiveRB + this->oppORB));

	TeamTotalReboundPercentage = (100 * this->teamTotalRB * static_cast<double>(2880)) / (static_cast<double>(2880) * (this->teamTotalRB + this->oppTRB));
	TeamAssistPercentage = (100 * this->teamAST / (((static_cast<double>(14400) / (static_cast<double>(2880)) * this->teamFGM) - this->teamFGM)));
	//asssist doesn't produce the wanted outcome, needs to be fixed
	// TeamStealPercentage = (100 * (teamSTL * static_cast<double>(2880))) / (static_cast<double>(2880) * oppPossessions);
	TeamBlockPercentage = (100 * (this->teamBLK * static_cast<double>(2880))) / (static_cast<double>(2880) * (this->oppFGA - this->opp3PA));
	TeamTurnoverPercentage = (100 * this->teamTOV) / (this->teamFGA + 0.44 * this->teamFTA + this->teamTOV);
	TeamUsagePercentage = 100 * ((this->teamFGA + 0.44 * this->teamFTA + this->teamTOV) * (static_cast<double>(2880))) / ((static_cast<double>(2880) * (this->teamFGA + 0.44 * this->teamFTA + this->teamTOV)));

	cout <<"Offensive rebound Percentage: " << fixed << setprecision(3) << TeamUsagePercentage << endl;
}

void Team::calcIndAdvStats()
{	
	for (int i = 0; i < this->playerList.size(); i++) {
		AdvPlayerStruct tempAdvPlayer;

		playerList[i].getBasicBoxScoreStats();

		tempAdvPlayer.TrueShootingPercentage = playerList[i].getTrueShooting();
		tempAdvPlayer.EffectiveFieldGoalPercentage = playerList[i].getEffectiveFGPercentage();
		tempAdvPlayer.ThreePointAttemptRate = playerList[i].getThreePointAttemptRate();
		tempAdvPlayer.FreeThrowAttemptRate = playerList[i].getFreeThrowAttemptRate();
		
		tempAdvPlayer.OffensiveReboundPercentage = (100 * (playerList[i].getORebounds() * static_cast<double>(2880))) / (playerList[i].getMinutesPlayed() * (this->teamOffensiveRB + this->oppDRB));
		tempAdvPlayer.DeffensiveReboundPercentage = (100 * (playerList[i].getDRebounds() * static_cast<double>(2880))) / (playerList[i].getMinutesPlayed() * (this->teamDeffensiveRB + this->oppORB));

		tempAdvPlayer.TotalReboundPercentage = (100 * playerList[i].getTRebounds() * static_cast<double>(2880)) / (playerList[i].getMinutesPlayed() * (this->teamTotalRB + this->oppTRB));
		tempAdvPlayer.AssistPercentage = (100 * playerList[i].getAssists() / (((playerList[i].getMinutesPlayed() / (static_cast<double>(2880)) * this->teamFGM) - playerList[i].getFieldGoalsMade())));
		// tempAdvPlayer.StealPercentage = (100 * (playerList[i].getSteals() * static_cast<double>(2880))) / (playerList[i].getMinutesPlayed() * oppPossessions);
		tempAdvPlayer.BlockPercentage = (100 * (playerList[i].getBlocks()  * static_cast<double>(2880))) / (playerList[i].getMinutesPlayed() * (this->oppFGA - this->opp3PA));
		tempAdvPlayer.TurnoverPercentage = (100 * playerList[i].getTurnovers()) / (playerList[i].getFieldGoalsAttemtped() + 0.44 * playerList[i].getFreeThrowsAttemtped() + playerList[i].getTurnovers());
		tempAdvPlayer.UsagePercentage = 100 * ((playerList[i].getFieldGoalsAttemtped() + 0.44 * playerList[i].getFreeThrowsAttemtped() + playerList[i].getTurnovers()) * (static_cast<double>(2880))) / (playerList[i].getMinutesPlayed() * (this->teamFGA + 0.44 * this->teamFTA + this->teamTOV));
		
		AdvPlayerValues.push_back(tempAdvPlayer);
		// 
		//cout << i+1 << ". Offensive rebound Percentage: " << fixed << setprecision(1) << AdvPlayerValues[i].UsagePercentage << endl;
	}
}

void Team::ListAllPlayers()
{
	for (int i = 0; i < this->playerList.size(); i++) {
		cout << playerList[i].getName() << endl;
	}
}

double Team::getTeamORB()
{
	return this->teamOffensiveRB;
}

double Team::getTeamDRB()
{
	return this->teamDeffensiveRB;
}

double Team::getTeamTRB()
{
	return this->teamTotalRB;
}

double Team::getTeamFGM()
{
	return this->teamFGM;
}

double Team::getTeamTrueShooting()
{
	this->TeamTrueShootingAttempts = (this->teamFTA * 0.44 + this->teamFGA);
	this->TeamTrueShootingPercentage = (this->teamPTS / (2 * this->TeamTrueShootingAttempts));

	this->TeamTrueShootingAttempts = this->TeamTrueShootingAttempts * 1000;
	this->TeamTrueShootingPercentage = this->TeamTrueShootingPercentage * 1000;

	return TeamTrueShootingPercentage;
}

double Team::getTeamEffectiveFGPercentage()
{
	this->TeamEffectiveFieldGoalPercentage = ((this->teamFGM + 0.5 * this->teamThreePM) / this->teamFGA) * 1000;

	return TeamEffectiveFieldGoalPercentage;
}

double Team::getTeamORBpercentage()
{
	this->TeamOffensiveReboundPercentage = ((100 * this->teamOffensiveRB * ((static_cast<double>(240) * 60) / 5)) / (this->teamInGameTime * (teamOffensiveRB + oppDRB)));

	return TeamOffensiveReboundPercentage;
}

double Team::getTeamDRBpercentage()
{
	this->TeamDeffensiveReboundPercentage = ((100 * this->teamDeffensiveRB * (static_cast<double>(240) / 5)) / (this->teamInGameTime * (teamDeffensiveRB + oppORB)));

	return TeamDeffensiveReboundPercentage;
}

double Team::getTeamTRBpercentage()
{
	this->TeamTotalReboundPercentage = ((100 * this->teamTotalRB * (static_cast<double>(240) / 5)) / (this->teamInGameTime * (teamTotalRB + oppTRB)));

	return TeamTotalReboundPercentage;
}

double Team::getTeamASTPercentage()
{
	this->TeamAssistPercentage = (100 * this->teamAST / (((this->teamInGameTime / (static_cast<double>(240) / 5)) * this->teamFGM) - this->teamFGM));

	return TeamAssistPercentage;
}

double Team::getTeamThreePointAttemptRate()
{
	this->TeamThreePointAttemptRate = (this->teamThreePA / this->teamFGA) * 1000;

	return TeamThreePointAttemptRate;
}

double Team::getTeamFreeThrowAttemptRate()
{
	this->TeamFreeThrowAttemptRate = (this->teamFTA / this->teamFGA) * 1000;

	return TeamFreeThrowAttemptRate;
}

double Team::getTeamStealPercentage()
{
	this->TeamStealPercentage = ((100 * (this->teamSTL * (static_cast <double>(240) / 5))) / (this->teamInGameTime / oppPossessions));

	return TeamStealPercentage;
}

double Team::getTeamBlockPercentage()
{
	this->TeamBlockPercentage = ((100 * (this->teamBLK * (static_cast <double>(240) / 5))) / (this->teamInGameTime * (oppFGA - opp3PA)));

	return TeamBlockPercentage;
}

double Team::getTeamTurnoverPercentage()
{
	this->TeamTurnoverPercentage = ((100 * this->teamTOV) / (this->teamFGA + 0.44 * this->teamFTA * this->teamTOV));

	return 0.0;
}

double Team::getTeamUsagePercentage()
{
	this->TeamUsagePercentage = (100 * (this->teamFGA + 0.44 * this->teamFTA * this->teamTOV) * (static_cast <double>(40) / 5)) / (this->teamInGameTime * (teamFGA + 0.44 * teamFTA * teamTOV));

	return TeamUsagePercentage;
}

void Team::setOpponentTeamStatistics(int opponentPossessions, int opponentORB, int opponentDRB, int opponentTRB, int opponentFGA, int opponent3PA)
{
	oppPossessions = opponentPossessions;
	oppORB = opponentORB;
	oppDRB = opponentDRB;
	oppTRB = opponentORB + opponentDRB;
	oppFGA = opponentFGA;
	opp3PA = opponent3PA;
}
