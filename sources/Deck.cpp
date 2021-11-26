//
// Created by nicksaxo on 06/05/20.
//
#include "../headers/Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    for (int suit = 1; suit <= N_SUITS; suit++)
        for (int value = 1; value <= N_VALUES; value++)
            this->deck.emplace_back(value, suit);
}

string Deck::display() {
    string result;
    for (Card card : Deck::getDeck())
        result += card.display() + "\n";

    return result;
}

vector<Card> &Deck::getDeck() {
    return this->deck;
}

void Deck::shuffle() {
    ::shuffle(this->deck.begin(),this->deck.end(), std::mt19937(std::random_device()()));
}

int Deck::get_size() {
    return this->deck.size();
}

vector<Card> Deck::give_cards(int n) {
    if (get_size() < n)
        __throw_invalid_argument("No cards available");

    vector<Card> cards;

    for (int i = 0; i < n; i++) {

        cards.emplace_back(this->deck.back());
        this->deck.pop_back();
    }

    return cards;
}

