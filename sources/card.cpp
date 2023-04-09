
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel{

    Card::Card(int number, string sha):value(number), shape(sha){}

    string Card::toString()const{
        string stringvalue;
        switch (value)
        {
        case 1:
            stringvalue = "Ace";
            break;

        case 2:
            stringvalue = "2";
            break;

        case 3:
            stringvalue = "3";
            break;

        case 4:
            stringvalue = "4";
            break;

        case 5:
            stringvalue = "5";
            break;

        case 6:
            stringvalue = "6";
            break;

        case 7:
            stringvalue = "7";
            break;

        case 8:
            stringvalue = "8";
            break;

        case 9:
            stringvalue = "9";
            break;

        case 10:
            stringvalue = "10";
            break;

        case 11:
            stringvalue = "Jack";
            break;

        case 12:
            stringvalue = "Queen";
            break;

        case 13:
            stringvalue = "King";
            break;

        }

        return stringvalue + " of " + shape;
    }

}
