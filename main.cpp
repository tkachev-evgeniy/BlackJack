#include <iostream>
#include "game.h"
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    cout << "Enter number of players (up to 4)" << endl;
    int nP=3;
    cin>>nP;
    nP=clamp(nP,1,4);

    cout << "Number of players set to " << nP << endl;

    cout << "Enter player names" << endl;
    std::vector<std::string> names(nP);
    cin>>ws;

    for (int i = 0; i<nP; ++i) {
        getline(cin,names[i]);
    }

    Player P1("P1");
    Deck deck1;
    deck1.Deal(P1);
    deck1.AdditionalCards(P1);
    cout << P1 << endl;
    P1.Clear();
    cout << P1 << endl;


}
