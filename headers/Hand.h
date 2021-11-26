//
// Created by nicksaxo on 07/05/20.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H

#include "Deck.h"
#include <algorithm>
#define CARDS 5

class Hand {

    private:
        vector<Card> hand;
        int score;

        bool is_royal_flush();
        bool is_straight_flush();
        bool is_poker();
        bool is_full_house();
        bool is_flush();
        bool is_straight();
        bool is_tris();
        bool is_two_pair();
        bool is_pair();

    public:
        Hand();
        Hand(const vector<Card> &hand);
        enum SCORE {HIGH_CARD, PAIR, TWO_PAIR, TRIS, STRAIGHT,
                    FLUSH, FULL_HOUSE, POKER, STRAIGHT_FLUSH, ROYAL_FLUSH};
        const vector<Card> &getHand();
        int getScore() const;

        void setScore(int score);
        void replace(Deck &deck, int number_of_cards);
        void replace(vector<Card> cards);
        string compute_score();
        string display();
};

#endif //POKER_HAND_H
