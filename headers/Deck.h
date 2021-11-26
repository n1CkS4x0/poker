//
// Created by nicksaxo on 06/05/20.
//
#ifndef POKER_DECK_H
#define POKER_DECK_H

#include "Card.h"
#include <vector>
#define N_SUITS 4
#define N_VALUES 13

class Deck {
    private:
        vector<Card> deck;

    public:
        Deck();
        vector<Card> &getDeck();
        string display();
        void shuffle();
        int get_size();
        vector<Card> give_cards(int n);
};

#endif //POKER_DECK_H
