#include "game.hpp"
using namespace std;
#include <random>
#include <algorithm>


 namespace ariel
 {
    Game::Game(Player& pp1, Player& pp2): player1(pp1), player2(pp2),log(""), lastTurn(""), draws(0), turn(0){

        if (pp1.getPlay())
        {
            throw invalid_argument("player 1 is in a game.");
        }

        if (pp2.getPlay())
        {
            throw invalid_argument("player 2 is in a game.");
        }
        
        for(int i = 1; i < 14; i++)
        {
            cardGame.push_back(Card(i, "Diamonds"));
        }

        for(int i = 1; i < 14; i++)
        {
            cardGame.push_back(Card(i, "Hearts"));
        }

        for(int i = 1; i < 14; i++)
        {
            cardGame.push_back(Card(i, "Clubs"));            
        }

        for(int i = 1; i < 14; i++)
        {
            cardGame.push_back(Card(i, "Spades"));            
        }

        random_device rd;
        mt19937 g(rd());
        shuffle(cardGame.begin(), cardGame.end(), g);

        while(!cardGame.empty())
        {
            pp1.addCardHand(cardGame.back());
            cardGame.pop_back();
            pp2.addCardHand(cardGame.back());
            cardGame.pop_back();
        }

        pp1.setPlay(true);
        pp2.setPlay(true);

    }

    void Game::playAll(){
        
        while(player1.getPlay() && player2.getPlay())
        {
            playTurn();
        }

    }

    void Game::printWiner(){
        
        if(player1.stacksize()== 0 && player2.stacksize() == 0)
        {
            if(player1.cardesTaken() > player2.cardesTaken())
            {
                cout << "The winner is " << player1.getName() << endl;
            }

            else if(player1.cardesTaken() < player2.cardesTaken())
            {
                cout << "The winner is " << player2.getName() << endl;
            }

            else
            {  
                cout << "The game  ended in draw." << endl;
            }
        }

        else
        {
            cout << "The game not end." << endl;
        }

    }

    void Game::printStats(){
        cout << "========================" << endl;

        cout << "player " << player1.getName() << " stats:" << endl;
        cout << "cards left: " << player1.stacksize() << endl;
        cout << "number of losses: " << turn - player1.getWin() - draws << endl;
        cout << "draw rate: " << ((double)draws/turn)*100. << "%" << endl;
        cout << "amout of draws: " << draws << endl;
        cout << "number of wins: " << player1.getWin() << endl;        
        cout << "win rate: " << ((double)player1.getWin()/turn)*100. << "%" << endl;
        
        cout << "========================" << endl;

        cout << "player " << player2.getName() << " stats:" << endl;
        cout << "cards left: " << player2.stacksize() << endl;
        cout << "number of losses: " << turn - player2.getWin() - draws << endl;
        cout << "draw rate: " << ((double)draws/turn)*100. << "%" << endl;
        cout << "amout of draws: " << draws << endl;
        cout << "number of wins: " << player2.getWin() << endl;        
        cout << "win rate: " << ((double)player2.getWin()/turn)*100. << "%" << endl;

        cout << "========================" << endl;
    }
  
    void Game::playTurn(){

        if(&player1 == &player2)
        {
            throw invalid_argument("the same player cant play against himself.");
        }

        if(player1.getPlay() && player2.getPlay())
        {
            turn++;
            lastTurn = "";
            Card c_p1 = player1.getCard();
            Card c_p2 = player2.getCard();

            player1.removeCardHand();
            player2.removeCardHand();

            cardGame.push_back(c_p1);
            cardGame.push_back(c_p2);


            lastTurn = player1.getName() + " played " + c_p1.toString() + " " + player2.getName() + " played " + c_p2.toString() + ". ";


            while(c_p1 == c_p2)
            {
                draws++;
                lastTurn += "Draw. ";

                if(player1.stacksize() < 2 || player2.stacksize() < 2)
                {
                    while (!cardGame.empty())
                    {
                        player2.addCardTaken(cardGame.back());
                        cardGame.pop_back();
                        player1.addCardTaken(cardGame.back());
                        cardGame.pop_back();
                    }
                    
                    while(player1.stacksize() != 0)
                    {
                        player1.addCardTaken(player1.getCard());
                        player1.removeCardHand();  
                    }

                    while (player2.stacksize() != 0)
                    {
                        player2.addCardTaken(player2.getCard());
                        player2.removeCardHand();  
                    }
                    
                    break;
                }

                c_p1 = player1.getCard();
                c_p2 = player2.getCard();

                player1.removeCardHand();
                player2.removeCardHand();

                cardGame.push_back(c_p1);
                cardGame.push_back(c_p2);

                lastTurn += player1.getName() + " played " + c_p1.toString() + " " + player2.getName() + " played " + c_p2.toString() + ". ";
                
            }

            if(c_p1 < c_p2)
            {
                lastTurn += player2.getName() + " wins.\n";
                player2.addWin();
                while (!cardGame.empty())
                {
                    player2.addCardTaken(cardGame.back());
                    cardGame.pop_back();
                }
            }

            else
            {
                lastTurn += player1.getName() + " wins.\n";
                player1.addWin();
                while (!cardGame.empty())
                {
                    player1.addCardTaken(cardGame.back());
                    cardGame.pop_back();
                }
            }

            if(player1.stacksize() == 0 || player2.stacksize() == 0)
            {
                player1.setPlay(false);
                player2.setPlay(false);

            }

            log += lastTurn;
        }

        else
        {
            throw logic_error("the game is over already!");
        }

    }

 }




