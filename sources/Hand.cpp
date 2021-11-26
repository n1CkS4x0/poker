//
// Created by nicksaxo on 07/05/20.
//

#include "../headers/Hand.h"

Hand::Hand(const vector<Card> &hand) : hand(hand) { compute_score(); }

Hand::Hand() {}

const vector<Card> &Hand::getHand() {
    return hand;
}

int Hand::getScore() const {
    return score;
}

void Hand::setScore(int score) {
    Hand::score = score;
}

string Hand::display() {
    string final_score = compute_score();
    string result;

    for (Card card : hand)
        result += card.display() + ", ";

    return "hand: " + result + " score: " + final_score;
}

string Hand::compute_score() {

    sort(this->hand.begin(),
         this->hand.end(),
        [](Card a, Card b){return a.getValue() < b.getValue();});

    if(is_royal_flush()){
        this->setScore(ROYAL_FLUSH);
        return "ROYAL_FLUSH";

    } else if (is_straight_flush()) {
        this->setScore(STRAIGHT_FLUSH);
        return "STRAIGHT_FLUSH";

    } else if (is_poker()) {
        this->setScore(POKER);
        return "POKER";

    } else if (is_full_house()) {
        this->setScore(FULL_HOUSE);
        return "FULL_HOUSE";

    } else if (is_flush()) {
        this->setScore(FLUSH);
        return "FLUSH";

    } else if (is_straight()) {
        this->setScore(STRAIGHT);
        return "STRAIGHT";

    } else if (is_tris()) {
        this->setScore(TRIS);
        return "TRIS";

    } else if (is_two_pair()) {
        this->setScore(TWO_PAIR);
        return "TWO_PAIR";

    } else if (is_pair()) {
        this->setScore(PAIR);
        return "PAIR";

    } else {
        this->setScore(HIGH_CARD);
        return "HIGH_CARD";
    }
}

bool Hand::is_royal_flush() {
    return this->hand.at(0).getValue() == 9 &&
           this->hand.at(CARDS - 1).getValue() == Card::A &&
           this->is_flush();
}

bool Hand::is_straight_flush() {
    return this->hand.at(CARDS - 1).getValue() - this->hand.at(0).getValue() == CARDS - 1
        && this->is_flush();
}

bool Hand::is_poker() {
    return this->hand.at(0) == this->hand.at(3) ||
           this->hand.at(1) == this->hand.at(4);
}

bool Hand::is_full_house() {
    return (this->hand.at(0) == this->hand.at(2) && this->hand.at(3) == this->hand.at(4)) ||
           (this->hand.at(2) == this->hand.at(4) && this->hand.at(0) == this->hand.at(1));
}

bool Hand::is_flush() {
    for (int i = CARDS - 1; i ; i--)
        if(this->hand.at(i - 1).getSuit() != this->hand.at(i).getSuit())
            return false;
    return true;
}

bool Hand::is_straight() {
    for (int i = CARDS - 1; i ; i--)
        if(this->hand.at(i - 1).getValue() != this->hand.at(i).getValue() - 1)
            return false;
    return true;
}

bool Hand::is_tris() {
    return this->hand.at(0) == this->hand.at(2)  ||
           this->hand.at(1) == this->hand.at(3)  ||
           this->hand.at(2) == this->hand.at(4);
}

bool Hand::is_two_pair() {
    return (this->hand.at(0) == this->hand.at(1) && this->hand.at(2) == this->hand.at(3)) ||
           (this->hand.at(1) == this->hand.at(2) && this->hand.at(3) == this->hand.at(4)) ||
           (this->hand.at(0) == this->hand.at(1) && this->hand.at(3) == this->hand.at(4));
}

bool Hand::is_pair() {
    for (int i = CARDS - 1; i ; i--)
        if(this->hand.at(i - 1) == this->hand.at(i))
            return true;
    return false;
}

void Hand::replace(Deck &deck, int n) {
    if (this->hand.size() < n)
        __throw_invalid_argument("Too much cards to replace");

    vector<Card> cards = deck.give_cards(n);
    int first = this->hand.size() - n;

    for (int i = 0; i < n; ++i)
        this->hand.at(first + i) = cards.at(i);
}

void Hand::replace(vector<Card> cards) {
    if (cards.size() > this->hand.size())
        __throw_invalid_argument("Too much cards to replace");

    for (int i = 0; i < cards.size(); ++i)
        this->hand.at(i) = cards.at(i);
}




