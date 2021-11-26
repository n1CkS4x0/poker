//
// Created by nicksaxo on 06/05/20.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H

#include <string>
using namespace std;

class Card {
    private:
        int suit;
        int value;

    public:
        enum SUITS {SPADES = 1, CLUBS = 2, DIAMONDS = 3, HEARTS= 4};
        enum FIGURES {J = 10, Q = 11, K = 12, A = 13};

        Card(int value, int suit);
        int getSuit() const;
        int getValue() const;
        bool operator==(const Card &card) const;
        bool operator!=(const Card &card) const;
        string display();
};

#endif //POKER_CARD_H
