#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T; cin >> T;
    int arr[10];
    
    while(T--) {
        int day=0, num=0, month[13]{0};
        for(int i=0; i<=9; i++) {
            cin >> arr[i];
        }

        for(int i=1; i<=9; i++) {
            if(!arr[i]) {
                month[i] = 1;
                day++;
            }
        }

        if(!arr[1]) {
            if(!arr[0]) month[10] = 1;
            month[11] = 1;
            if(!arr[2]) month[12] = 1;

            for(int i=0; i<=9; i++) {
                if(!arr[i]) day++;
            } 
        }
        if(!arr[2]) {
            for(int i=0; i<=9; i++) {
                if(!arr[i]) day++;
            }
        }

        for(int i=1; i<=12; i++) {
            if(month[i]) {
                num += day;
                if(i!=2 && !arr[3] && !arr[0]) num++;
                if(i!=2 && !arr[3] && !arr[1]) {
                    if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) num++;
                }                
            }
        }

        cout << num << '\n';
    }

    return 0;
}   