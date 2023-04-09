#pragma once
#include <string>
using namespace std;

namespace ariel
{
    class Card
    {
        private:
            int value;
            string shape;
        
        public:

            Card(int value, string shape);

            int getValue()const{
                return value;
            }

            string getShape()const{
                return shape;
            }

            bool operator<(const Card& other)const{
                return (value == 1 && other.value == 2) or (value == 2 && other.value > 2) or (value > 2 && other.value > value) or (other.value == 1 and value > 2);
            }

            bool operator==(const Card& other)const{
               return value == other.value;
            }

            string toString()const;
    };
}