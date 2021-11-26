//
// Created by nicksaxo on 07/05/20.
//

#ifndef POKER_MATCH_H
#define POKER_MATCH_H

#include "Hand.h"
#define HANDS 5

class Match {

    private:
        Deck deck;
        vector<Hand> hands;

    public:
        Match();
        void replace(int hand, int number_of_cards);
        string display();

        Deck &getDeck();
        vector<Hand> &getHands() ;
};

#endif //POKER_MATCH_H
