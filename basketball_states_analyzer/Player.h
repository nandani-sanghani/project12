#pragma once
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// #ifndef PLAYER_H  For some reason this doesn't work
#define PLAYER_H

class Player {
protected:
    string playerName, position;
    int playerNumber;

public:
    void setPlayerName(string name, int teamNumber);
};

class opposingPlayer :public Player {
public:


private:
    string teamName;
};

class myPlayer :public Player {
public:
    

    void setPlayerStats(int MinutesPlayed, int SecondsPlayed, double FieldGoalsMade, double FieldGoalsAttempted, double ThreePointersMade, double ThreePointersAttempted, double FreeThrowsMade, double FreeThrowsAttempted, int OffensiveRebounds, int DeffensiveRebounds, int Assists, int Steals, int Blocks, int Turnovers, int PersonalFouls);
    void getBasicBoxScoreStats();
    void calculateAdvancedStatistics();

    void printPlayerBasicStats();

    // Basic statistics
    struct MyStruct
    {

    };
    double getFieldGoalsMade();
    double getFieldGoalsAttemtped();

    double getThreePointersMade();
    double getThreePointersAttemtped();

    double getFreeThrowsMade();
    double getFreeThrowsAttemtped();

    double getFieldGoalPercentage();
    void getThreePointPercentage();    
    void getFreeThrowPercentage();
    
    string getName();
    int getMinutesPlayed();
    int getPlusMinus(int plusMinus);

    double getORebounds();
    double getDRebounds();
    double getTRebounds();
    double getAssists();
    double getSteals();
    double getBlocks();
    double getTurnovers();



    


    // Advanced metrics

    double getTrueShooting();
    double getEffectiveFGPercentage();
    double getThreePointAttemptRate();
    double getFreeThrowAttemptRate();
    /* for now - mora ici u team jer su advanced funkcije
    * 
    double getORBpercentage();
    double getDRBpercentage();
    double getTRBpercentage();
    double getASTPercentage();
    double getSTLPercentage();
    
    double getStealPercentage();
    double getBlockPercentage();
    double getTurnoverPercentage();
    double getUsagePercentage();
    */
   

    myPlayer() {};
    myPlayer(int MinutesPlayed, int SecondsPlayed, double FieldGoalsMade, double FieldGoalsAttempted, double ThreePointersMade, double ThreePointersAttempted, double FreeThrowsMade, double FreeThrowsAttempted, int OffensiveRebounds, int DeffensiveRebounds, int Assists, int Steals, int Blocks, int Turnovers, int PersonalFouls);

private:
    int MinutesPlayed, SecondsPlayed, inGameTime;
    double FGA, FGM, FGPercentage;
    double ThreePM, ThreePA, ThreePPercentage;
    double FTM, FTA, FTPercentage;
    int OffensiveRB, DeffensiveRB, TotalRB;
    int AST = 0;
    int BLK = 0;
    int TOV = 0;
    int PTS = 0;
    int STL = 0;
    int PF = 0;
    int plusMinus = 0;


    // prebaci u team.cpp
    int teamORB = 0 , teamDRB = 0, teamTRB = 0;
    int teamFTA, teamFTM, teamTOV;
    double teamFGM, teamFGA;

    //opponents Metrics
    int oppPossessions;
    int oppORB = 0, oppDRB = 0, oppTRB = 0;
    int oppFGA, opp3PA;

    //advanced metrics   

    double ThreePointAttemptRate, FreeThrowAttemptRate;
    double TrueShootingAttempts, TrueShootingPercentage;
    double EffectiveFieldGoalPercentage;

    

    //pointeri


};