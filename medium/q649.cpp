#include <iostream>
using namespace std;

#include <queue>

string predictPartyVictory(string senate) {
    int RS, DS;
    RS = DS = 0;
    int toBanR, toBanD;
    toBanR = toBanD = 0;

    queue<char> q;

    for (char c:senate) {
        if (c == 'R') RS++;
        else DS++;

        q.push(c);
    }

    while (true) {
        if (RS == 0) return "Dire";
        if (DS == 0) return "Radiant";

        if (q.front() == 'R') {
            if (toBanR) {
                q.pop();
                toBanR--;
            } else {
                DS--;
                toBanD++;
                q.pop();
                q.push('R');
            }
        } else {
            if (toBanD) {
                q.pop();
                toBanD--;
            } else {
                RS--;
                toBanR++;
                q.pop();
                q.push('D');
            }
        }
    }
    
    return "";
}