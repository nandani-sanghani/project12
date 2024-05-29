#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

#include "Player.h"

void Player::setPlayerName(string name, int teamNumber)
{
	playerName = name;
	playerNumber = teamNumber;
}

void myPlayer::setPlayerStats(int MinutesPlayed, int SecondsPlayed, double FieldGoalsMade, double FieldGoalsAttempted, double ThreePointersMade, double ThreePointersAttempted, double FreeThrowsMade, double FreeThrowsAttempted, int OffensiveRebounds, int DeffensiveRebounds, int Assists, int Steals, int Blocks, int Turnovers, int PersonalFouls)
{
	this->MinutesPlayed = MinutesPlayed;
	this->SecondsPlayed = SecondsPlayed;
	this->inGameTime = (this->MinutesPlayed * 60) + this->SecondsPlayed;

	this->FGM = FieldGoalsMade;
	this->FGA = FieldGoalsAttempted;
	this->ThreePM = ThreePointersMade;
	this->ThreePA = ThreePointersAttempted;
	this->FTM = FreeThrowsMade;
	this->FTA = FreeThrowsAttempted;

	this->OffensiveRB = OffensiveRebounds;
	this->DeffensiveRB = DeffensiveRebounds;
	
	this->AST = Assists;
	this->STL = Steals;
	this->BLK = Blocks;
	this->TOV = Turnovers;
	this->PF = PersonalFouls;
}

void myPlayer::getBasicBoxScoreStats()
{
	this->FGPercentage = (this->FGM / this->FGA);
	this->ThreePPercentage = (this->ThreePM / this->ThreePA);
	this->FTPercentage = (this->FTM / this->FTA) * 1000;
	this->TotalRB = this->OffensiveRB + this->DeffensiveRB;
	this->PTS = ((this->FGM - this->ThreePM) * 2) + (this->ThreePM * 3) + this->FTM;
	
}

void myPlayer::calculateAdvancedStatistics()
{
	this->getTrueShooting();
	this->getEffectiveFGPercentage();
	this->getThreePointAttemptRate();
	this->getFreeThrowAttemptRate();
	/*
	this->getORBpercentage();
	this->getDRBpercentage();
	this->getTRBpercentage();
	this->getASTPercentage();
	
	this->getStealPercentage();
	this->getBlockPercentage();
	this->getTurnoverPercentage();
	this->getUsagePercentage();
	*/
}

void myPlayer::printPlayerBasicStats()
{
	cout << "MP: " << this->MinutesPlayed << ":" << this->SecondsPlayed << endl;
	cout << "FG: " << this->FGM << " FGA: " << this->FGA << " FG%: " << setprecision(3) << this->FGPercentage << "%" << endl;
	cout << "3PM: " << this->ThreePM << " 3PA: " << this->ThreePA << " 3P%: " << setprecision(3) << this->ThreePPercentage << "%" << endl;
	cout << "FT: " << this->FTM << " FTA: " << this->FTA << " FT%: " << setprecision(3) << this->FTPercentage << "%" << endl;
	cout << "ORB: " << this->OffensiveRB << " DRB: " << this->DeffensiveRB << " TRB: " << this->TotalRB << endl;
	cout << "AST: " << this->AST << " STL: " << this->STL << " BLK: " << this->BLK << " TOV: " << this->TOV << " PF: " << this->PF << " PTS: " << this->PTS << endl;

}

void myPlayer::getThreePointPercentage() 
{
	this->ThreePPercentage = (this->ThreePM / this->ThreePA) * 1000;

	//cout << "Your three point percentage is: ." << fixed << setprecision(0) << this->ThreePPercentage;
}

double myPlayer::getFieldGoalsMade()
{
	return this->FGM;
}

double myPlayer::getFieldGoalsAttemtped()
{
	return this->FGA;
}

double myPlayer::getThreePointersMade()
{
	return this->ThreePM;
}

double myPlayer::getThreePointersAttemtped()
{
	return this->ThreePA;
}

double myPlayer::getFreeThrowsMade()
{
	return this->FTM;
}

double myPlayer::getFreeThrowsAttemtped()
{
	return this->FTA;
}

double myPlayer::getFieldGoalPercentage()
{	
	this->FGPercentage = (this->FGM / this->FGA) * 1000;

	//cout << "Your field goal percentage is: ." << fixed << setprecision(0) << this->FGPercentage << endl;

	return this->FGM;
	return this->FGA;
}

void myPlayer::getFreeThrowPercentage()
{
	this->FTPercentage = (this->FTM / this->FTA) * 1000;

	//cout << "Your free throw percentage is: ." << fixed << setprecision(0) << this->FTPercentage;
}

string myPlayer::getName()
{
	return this->playerName;
}

int myPlayer::getMinutesPlayed()
{
	this->inGameTime = (this->MinutesPlayed * 60) + this->SecondsPlayed;
	
	return inGameTime;
}

int myPlayer::getPlusMinus(int plusMinus)
{

	return 0;
}

double myPlayer::getORebounds()
{
	return this->OffensiveRB;
}

double myPlayer::getDRebounds()
{
	return this->DeffensiveRB;
}

double myPlayer::getTRebounds()
{
	return this->TotalRB;
}

double myPlayer::getAssists()
{
	return this->AST;
}

double myPlayer::getSteals()
{
	return this->STL;
}

double myPlayer::getBlocks()
{
	return this->BLK;
}

double myPlayer::getTurnovers()
{
	return this->TOV;
}

double myPlayer::getTrueShooting()
{

	this->TrueShootingAttempts = (this->FTA * 0.44 + this->FGA);
	this->TrueShootingPercentage = (this->PTS / (2 * this->TrueShootingAttempts));

	this->TrueShootingAttempts = this->TrueShootingAttempts * 1000;
	this->TrueShootingPercentage = this->TrueShootingPercentage * 1000;

	/* Not needed for now
	cout << "True shooting attempts: ." << fixed << setprecision(0) << this->TrueShootingAttempts << endl; 
	*/
	//cout << "True shooting percentage: ." << fixed << setprecision(0) << this->TrueShootingPercentage << endl;
	

	return TrueShootingPercentage;
}

double myPlayer::getEffectiveFGPercentage()
{
	this->EffectiveFieldGoalPercentage = ((this->FGM + 0.5 * this->ThreePM) / this->FGA) * 1000;

	//cout << "Effective field goal percentage: ." << fixed << setprecision(0) << this->EffectiveFieldGoalPercentage << endl;

	return EffectiveFieldGoalPercentage;
}
/*
double myPlayer::getORBpercentage()
{
	this->OffensiveReboundPercentage = (100 * (this->OffensiveRB * static_cast<double>(2880))) / (this->inGameTime * (teamORB + oppDRB));

	cout << "Offensive rebound percentage: " << fixed << setprecision(9) << this->OffensiveReboundPercentage << "%" << endl;
	cout << oppDRB << endl;

	return this->OffensiveReboundPercentage;
}

double myPlayer::getDRBpercentage()
{
	this->DeffensiveReboundPercentage = ((100 * this->DeffensiveRB * (static_cast<double>(240) / 5)) / (this->inGameTime * (teamDRB + oppORB)));

	cout << "Deffensive rebound percentage: " << fixed << setprecision(1) << this->DeffensiveReboundPercentage << "%" << endl;

	return DeffensiveReboundPercentage;
}

double myPlayer::getTRBpercentage()
{
	this->TotalReboundPercentage = ((100 * this->TotalRB * (static_cast<double>(240) / 5)) / (this->inGameTime * (teamTRB + oppTRB)));

	cout << "Deffensive rebound percentage: " << fixed << setprecision(1) << this->TotalReboundPercentage << "%" << endl;

	return TotalReboundPercentage;
}

double myPlayer::getASTPercentage()
{
	this->AssistPercentage = (100 * this->AST / (((this->inGameTime / (static_cast<double>(240) / 5)) * teamFGM) - this->FGM));

	cout << "Assist percentage: " << fixed << setprecision(1) << this->AssistPercentage << "%" << endl;

	return AssistPercentage;
}
*/
double myPlayer::getThreePointAttemptRate()
{
	this->ThreePointAttemptRate = (this->ThreePA / this->FGA) * 1000;

	//cout << "Three point attempt rate is: ." << fixed << setprecision(0) << this->ThreePointAttemptRate << endl;

	return ThreePointAttemptRate;
}

double myPlayer::getFreeThrowAttemptRate()
{
	this->FreeThrowAttemptRate = (this->FTA / this->FGA) * 1000;

	//cout << "Free throw attempt rate is: ." << fixed << setprecision(0) << this->FreeThrowAttemptRate << endl;

	return FreeThrowAttemptRate;
}
/*
double myPlayer::getStealPercentage()
{
	this->StealPercentage = ((100 * (this->STL * (static_cast <double>(240) / 5))) / (this->inGameTime / oppPossessions));

	cout << "Steal percentage: " << fixed << setprecision(1) << this->StealPercentage << endl;

	return StealPercentage;
}

double myPlayer::getBlockPercentage()
{
	this->BlockPercentage = ((100 * (this->BLK * (static_cast <double>(240) / 5))) / (this->inGameTime * (oppFGA - opp3PA)));

	cout << "Block percentage: " << fixed << setprecision(1) << this->BlockPercentage << endl;

	return BlockPercentage;
}

double myPlayer::getTurnoverPercentage()
{
	this->TurnoverPercentage = ((100 * this->TOV) / (this->FGA + 0.44 * this->FTA * this->TOV));

	cout << "Turnover percentage: " << fixed << setprecision(1) << this->TurnoverPercentage << endl;

	return TurnoverPercentage;
}

double myPlayer::getUsagePercentage()
{
	this->UsagePercentage = (100 * (this->FGA + 0.44 * this->FTA * this->TOV) * (static_cast <double>(40) / 5)) / (this->inGameTime * (teamFGA + 0.44 * teamFTA * teamTOV));

	cout << "Usage percentage: " << fixed << setprecision(3) << this->UsagePercentage << endl;

	return UsagePercentage;
}
*/
myPlayer::myPlayer(int MinutesPlayed, int SecondsPlayed, double FieldGoalsMade, double FieldGoalsAttempted, double ThreePointersMade, double ThreePointersAttempted, double FreeThrowsMade, double FreeThrowsAttempted, int OffensiveRebounds, int DeffensiveRebounds, int Assists, int Steals, int Blocks, int Turnovers, int PersonalFouls)
{
	setPlayerStats(MinutesPlayed, SecondsPlayed, FieldGoalsMade, FieldGoalsAttempted, ThreePointersMade, ThreePointersAttempted, FreeThrowsMade, FreeThrowsAttempted, OffensiveRebounds, DeffensiveRebounds, Assists, Steals, Blocks, Turnovers, PersonalFouls);

}
