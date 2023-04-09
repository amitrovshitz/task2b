#pragma once
#include <string>
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Player
    {
        private:
            string playername;
            vector < Card> hand_card;
            vector < Card> taken_card;
            bool play;
            unsigned int win;
        
        public:
            Player(string name = "defult");
            unsigned long stacksize()const{
                return hand_card.size();
            }

            unsigned long cardesTaken()const{
                return taken_card.size();
            }

            void addCardHand(const Card& card){
                hand_card.push_back(card);
            }

            void addCardTaken(const Card& card){
                taken_card.push_back(card);
            }

            void removeCardHand(){
                hand_card.pop_back();
            }

            void removeCardTaken(){
                taken_card.pop_back();
            }

            const Card& getCard()const{
                return hand_card.back();
            }

            bool getPlay()const{
                return play;
            }
            
            void setPlay(bool splay){
                play = splay;
            }

            string getName()const{
                return playername;
            }

            unsigned int getWin()const{
                return win;
            }

            void addWin(){
                win++;
            }
    };
}