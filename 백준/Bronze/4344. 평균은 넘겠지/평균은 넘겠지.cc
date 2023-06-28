#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int C, N, score, sum, cnt;
    double avg, mta;
    vector<int> v;
    cin >> C;
    for(int i=0; i<C; i++) {
        cnt=0;
        sum=0;
        v.clear();
        cin >> N;
        for(int j=0; j<N; j++) {
            cin >> score;
            sum += score;
            v.push_back(score);
        }
        avg = sum/N;
        for(int j=0; j<N; j++) {
            if(v[j]>avg) cnt++;
        }
        mta = 100.0/((double)N/(double)cnt);
        mta = round(mta*1000)*0.001;
        cout << fixed;
        cout.precision(3);
        cout << mta << '%' << '\n';
    }
}