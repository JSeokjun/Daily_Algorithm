#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<int,int>> V;
    
    for (int i=0; i<N; i++) {
        int L, H; cin >> L >> H;
        V.push_back({L, H});
    }

    sort(V.begin(), V.end(), [](auto &a, auto&b) {
        return a.first < b.first;
    });

    int minArea = 0, i = 0;

    while (1) {
        bool isHigher = false;
        int preL = V[i].first, preH = V[i].second;
        int maxNextL = 0, maxNextH = 0;

        minArea += preH;

        for (int j=i+1; j<N; j++) {
            int nextL = V[j].first, nextH = V[j].second;

            if (preH < nextH) {
                minArea += (nextL - preL - 1) * preH;

                if (j == N-1) {
                    minArea += nextH;
                }

                i = j;
                isHigher = true;
                break;
            }

            if (nextH > maxNextH) {
                maxNextH = nextH;
                maxNextL = nextL;
                i = j;
            }
        }

        if (!isHigher) {
            minArea += (maxNextL - preL - 1) * maxNextH;

            if (i == N-1) {
                minArea += maxNextH;
            }

        }

        if (i == N-1) break;
    }

    cout << minArea;

    return 0;
}