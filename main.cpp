#include <iostream>
#include "headers/Match.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#define MATCHES 4
#define print cout
using namespace std;

int main() {


    srand (time(NULL));

    Match matches[MATCHES];

    for(Match match : matches){
        print << match.display() << "\n\n";
    }

    vector<Hand> max_hands;

    for(Match &match : matches){
        Hand max_current_hand = match.getHands().at(0);

        for(Hand &hand : match.getHands()){
             if(rand() % 2 == 1){
                 hand.replace(match.getDeck(), rand() % CARDS + 1);
             }
             if(hand.getScore() > max_current_hand.getScore()){
                 max_current_hand = hand;
             }
        }
        max_hands.emplace_back(max_current_hand);
    }

    print << "After replacing \n\n" << endl;

    for(Match match : matches){
        print << match.display() << "Remaining cards: " << match.getDeck().get_size() << "\n\n";
    }

    for (int i = 0; i < max_hands.size(); ++i) {
        int pos = max_hands.at(i).display().find("score:");
        print << "major hand of " << (i + 1) << " match: " << max_hands.at(i).display().substr(pos  + 6)  << endl;
    }

    ofstream myfile;
    myfile.open ("results.txt");

    for (Match match : matches) {
        myfile << match.display() << endl;
    }

    myfile.close();

    return 0;
}

void count_time(){
    auto t1 = chrono::high_resolution_clock::now();

    srand (time(NULL));

    Match matches[MATCHES];

    for(Match match : matches){
        print << match.display() << "\n\n";
    }

    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

    print << duration << " millisecs\n";
}

