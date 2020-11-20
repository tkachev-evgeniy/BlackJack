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
    cin>>ws;

    for (int i = 0; i<nP; ++i) {
        getline(cin,names[i]);
    }

    Game newgame(names);
    bool flag = 1;
    while (flag) {
    newgame.Play();
    flag = 0;
    cout << "Do you want to play another round? (Y/N): ";
    char response;
    cin >> response;
    flag = (response == 'y' || response == 'Y');
    }
}
