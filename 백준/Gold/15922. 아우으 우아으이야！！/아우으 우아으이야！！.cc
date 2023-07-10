#include <iostream>
using namespace std;

int main() {
    int n, m, len=0;
    cin >> n;
    int arr[2];
    cin >> arr[0] >> arr[1];
    for(int i=0; i<n-1; i++) {
        cin >> m;
        if(arr[1]>=m) {
            cin >> m;
            if(m<=arr[1]) continue;
            else arr[1] = m;
        }
        else {
            len += (arr[1]-arr[0]);
            arr[0] = m;
            cin >> arr[1];
        }
    }
    len += (arr[1]-arr[0]);
    cout << len;
}   