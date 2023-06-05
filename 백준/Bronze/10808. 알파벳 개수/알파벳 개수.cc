#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    int arr[26]={};
    for(int i=0; i<S.length(); i++) {
        arr[S[i]-'a']+=1;
    } 
    for(int i=0; i<26; i++) {
        cout << arr[i] << ' ';
    }
}