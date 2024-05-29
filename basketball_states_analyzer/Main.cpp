#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

#include "Player.h"
#include "Team.h"

int main() {
     myPlayer Lillard;
     myPlayer Giannis;
     myPlayer Brook;
     myPlayer Malik;
     myPlayer Crowder;
     myPlayer Portis;
     myPlayer Pat;
     myPlayer Beverley;
     myPlayer Green;
     myPlayer JacksonJr;

     Team Bucks;
     /* 
     
     Not needed anymore, it was needed for previous testing
     */
    Bucks.oppDRB = 33;
    Bucks.oppORB = 7;
    Bucks.oppTRB = 40;
    Bucks.oppFGA = 83;
    Bucks.opp3PA = 26;
    

    // Adding players and their stats for their game

    Giannis.setPlayerStats  (36, 37, 15, 17, 0, 0, 5, 9, 0, 4, 12, 0, 0, 1, 5);
    Lillard.setPlayerStats  (34, 58, 7, 21, 3, 13, 7, 7, 2, 3, 7, 1, 0, 4, 2);    
    Brook.setPlayerStats    (34, 37, 5, 14, 2, 9, 2, 2, 2, 9, 2, 2, 4, 1, 2);
    Malik.setPlayerStats    (29, 45, 3, 10, 3, 10, 0, 0, 0, 2, 0, 2, 0, 0, 4);
    Crowder.setPlayerStats  (24, 8, 2, 4, 0, 2, 0, 0, 1, 4, 0, 1, 0, 1, 2);
    Portis.setPlayerStats   (24, 46, 7, 12, 1, 1, 0, 0, 3, 4, 2, 0, 0, 2, 1);
    Pat.setPlayerStats      (23, 52, 1, 3, 0, 1, 0, 0, 2, 3, 0, 2, 1, 2, 1);
    Beverley.setPlayerStats (14, 13, 0, 4, 0, 4, 1, 2, 1, 3, 4, 1, 0, 1, 1);
    Green.setPlayerStats    (14, 5, 2, 4, 2, 4, 0, 0, 0, 1, 1, 1, 0, 1, 2);
    JacksonJr.setPlayerStats(2, 59, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2);

    // Adding players into initialized team

    Bucks.addPlayer(Giannis);
    Bucks.addPlayer(Lillard);    
    Bucks.addPlayer(Brook);
    Bucks.addPlayer(Malik);
    Bucks.addPlayer(Crowder);
    Bucks.addPlayer(Portis);
    Bucks.addPlayer(Pat);
    Bucks.addPlayer(Beverley);
    Bucks.addPlayer(Green);
    Bucks.addPlayer(JacksonJr);

    Bucks.calcSumOfTeamStats();
    Bucks.calculateTeamStats();

    Bucks.calcIndAdvStats();

    Bucks.calcTeamAdvStats();

    return 0;
}


