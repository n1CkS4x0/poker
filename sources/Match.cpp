//
// Created by nicksaxo on 07/05/20.
//
#include "../headers/Match.h"

Match::Match() {
    this->deck.shuffle();

    for (int i = 0; i < HANDS; ++i)
        this->hands.emplace_back(deck.give_cards(HANDS));
}

void Match::replace(int hand, int number_of_cards) {
    if(HANDS < hand)
        __throw_invalid_argument("Hand no present");

    this->hands.at(hand).replace(this->deck, number_of_cards);
}

Deck &Match::getDeck()  {
    return deck;
}

vector<Hand> &Match::getHands() {
    return hands;
}

string Match::display() {
    string result = "match:\n";

    for(Hand hand : this->hands)
        result += hand.display() + "\n";

    return result;
}



