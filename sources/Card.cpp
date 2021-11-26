//
// Created by nicksaxo on 06/05/20.
//

#include "../headers/Card.h"

Card::Card(int value, int suit) : value(value) , suit(suit) {}

int Card::getSuit() const {
    return this->suit;
}

int Card::getValue() const {
    return this->value;
}

string Card::display() {
    string real_value;
    string real_suit;

    switch (Card::getValue()) {

        case FIGURES::J: real_value = "J"; break;
        case FIGURES::Q: real_value = "Q"; break;
        case FIGURES::K: real_value = "K"; break;
        case FIGURES::A: real_value = "A"; break;

        default: real_value = to_string(Card::getValue() + 1);
    }

    switch (Card::getSuit()) {

        case Card::SPADES:   real_suit = "p";   break;
        case Card::CLUBS:    real_suit = "f";   break;
        case Card::DIAMONDS: real_suit = "q";   break;
        case Card::HEARTS:   real_suit = "c";   break;
    }

    return real_value + real_suit;
}


bool Card::operator==(const Card &card) const {
    return this->getValue() == card.getValue();
}

bool Card::operator!=(const Card &card) const {
    return this->getValue() != card.getValue();
}



