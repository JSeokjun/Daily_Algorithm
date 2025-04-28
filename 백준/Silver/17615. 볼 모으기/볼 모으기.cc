#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string ball; cin >> ball;

    int numRed = 0, numBlue = 0;

    for (int i=0; i<ball.size(); i++) {
        if (ball[i] == 'R') numRed++;
        else if (ball[i] == 'B') numBlue++;
    }

    if (numRed == 0 || numBlue == 0) {
        cout << 0;
        return 0;
    }

    int cntRed = 0, moveBlue = 0;
    int cntBlue = 0, moveRed = 0;

    for (int i=0; i<ball.size(); i++) {
        if (ball[i] == 'R') cntRed++;
        else if (ball[i] == 'B') moveBlue++;
        
        if (cntRed == numRed) break;
    }

    for (int i=0; i<ball.size(); i++) {
        if (ball[i] == 'R') moveRed++;
        else if (ball[i] == 'B') cntBlue++;
        
        if (cntBlue == numBlue) break;
    }

    int minRight = min(moveBlue, moveRed);

    cntRed = 0, moveBlue = 0;
    cntBlue = 0, moveRed = 0;

    for (int i=ball.size()-1; i>=0; i--) {
        if (ball[i] == 'R') cntRed++;
        else if (ball[i] == 'B') moveBlue++;
        
        if (cntRed == numRed) break;
    }

    for (int i=ball.size()-1; i>=0; i--) {
        if (ball[i] == 'R') moveRed++;
        else if (ball[i] == 'B') cntBlue++;
        
        if (cntBlue == numBlue) break;
    }

    int minLeft = min(moveBlue, moveRed);

    cout << min(minRight, minLeft);

    return 0;
}