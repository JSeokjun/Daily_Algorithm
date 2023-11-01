#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int arr[8];
    double min_dst = 0;
    double tmp = 0;

    for(int i=0; i<8; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<=4; i+=2) {
        min_dst += sqrt((arr[i]-arr[i+2])*(arr[i]-arr[i+2]) + (arr[i+1]-arr[i+3])*(arr[i+1]-arr[i+3]));
    }

    tmp += sqrt((arr[0]-arr[2])*(arr[0]-arr[2]) + (arr[1]-arr[3])*(arr[1]-arr[3]));
    tmp += sqrt((arr[2]-arr[6])*(arr[2]-arr[6]) + (arr[3]-arr[7])*(arr[3]-arr[7]));
    tmp += sqrt((arr[6]-arr[4])*(arr[6]-arr[4]) + (arr[7]-arr[5])*(arr[7]-arr[5]));
    if(tmp < min_dst) min_dst = tmp;
    tmp = 0;

    tmp += sqrt((arr[0]-arr[4])*(arr[0]-arr[4]) + (arr[1]-arr[5])*(arr[1]-arr[5]));
    tmp += sqrt((arr[4]-arr[2])*(arr[4]-arr[2]) + (arr[5]-arr[3])*(arr[5]-arr[3]));
    tmp += sqrt((arr[2]-arr[6])*(arr[2]-arr[6]) + (arr[3]-arr[7])*(arr[3]-arr[7]));
    if(tmp < min_dst) min_dst = tmp;
    tmp = 0;

    tmp += sqrt((arr[0]-arr[4])*(arr[0]-arr[4]) + (arr[1]-arr[5])*(arr[1]-arr[5]));
    tmp += sqrt((arr[4]-arr[6])*(arr[4]-arr[6]) + (arr[5]-arr[7])*(arr[5]-arr[7]));
    tmp += sqrt((arr[6]-arr[2])*(arr[6]-arr[2]) + (arr[7]-arr[3])*(arr[7]-arr[3]));
    if(tmp < min_dst) min_dst = tmp;
    tmp = 0;

    tmp += sqrt((arr[0]-arr[6])*(arr[0]-arr[6]) + (arr[1]-arr[7])*(arr[1]-arr[7]));
    tmp += sqrt((arr[6]-arr[2])*(arr[6]-arr[2]) + (arr[7]-arr[3])*(arr[7]-arr[3]));
    tmp += sqrt((arr[2]-arr[4])*(arr[2]-arr[4]) + (arr[3]-arr[5])*(arr[3]-arr[5]));
    if(tmp < min_dst) min_dst = tmp;
    tmp = 0;

    tmp += sqrt((arr[0]-arr[6])*(arr[0]-arr[6]) + (arr[1]-arr[7])*(arr[1]-arr[7]));
    tmp += sqrt((arr[6]-arr[4])*(arr[6]-arr[4]) + (arr[7]-arr[5])*(arr[7]-arr[5]));
    tmp += sqrt((arr[4]-arr[2])*(arr[4]-arr[2]) + (arr[5]-arr[3])*(arr[5]-arr[3]));
    if(tmp < min_dst) min_dst = tmp;

    cout << (int)min_dst;

    return 0;
}   