#pragma once
#include "player.hpp"
#include "card.hpp"
#include <iostream>

namespace ariel
{
    class Game
    {
    private:
        Player& player1;
        Player& player2;
        string log;
        string lastTurn;
        vector<Card> cardGame;
        unsigned int draws;
        unsigned int turn;

    public:
    
        Game(Player& pp1, Player& pp2);
        void playTurn();
        void playAll();
        void printLastTurn()const{
            cout << lastTurn << endl;
        }
        void printWiner();
        void printLog()const{
            cout << log << endl;
        }
        void printStats();
     
    };
}