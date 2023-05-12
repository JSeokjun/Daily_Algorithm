#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int T, N, C, tC;
    double G, tG;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        tC = 0;
        tG = 0.0;
        for(int j=0; j<N; j++){
            cin >> C;
            cin >> G;
            tC += C;
            tG += C*G;
        }
        printf("%d %.1f", tC, round(tG/tC*10)/10);
        cout << '\n';
    }
}