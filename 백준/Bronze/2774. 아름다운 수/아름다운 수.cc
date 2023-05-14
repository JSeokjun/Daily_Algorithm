#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, B;
    string X;
    int arr[10];
    cin >> T;
    for(int i=0; i<T; i++) {
        B = 0;
        for(int j=0; j<10; j++) {
            arr[j] = 0;
        }
        cin >> X;
        for(int j=0; j<X.length(); j++) {
            
            arr[X[j]-'0'] = 1;
        }
        for(int j=0; j<10; j++) {
            if(arr[j]==1) B+=1; 
        }
        cout << B;
        cout << '\n';
    }
}