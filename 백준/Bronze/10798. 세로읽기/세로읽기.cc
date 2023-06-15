#include <iostream>
using namespace std;

int main() {
    char arr[5][15];
    string str;

    for(int i=0; i<5; i++) {
        for(int j=0; j<15; j++) {
            arr[i][j]='.';
        }
    }

    for(int i=0; i<5; i++) {
        cin >> str;
        for(int j=0; j<str.length(); j++) {
            arr[i][j] = str[j];
        } 
    }

    for(int i=0; i<15; i++) {
        for(int j=0; j<5; j++) {
            if(arr[j][i]=='.') continue;
            cout << arr[j][i];
        }
    }
}