#include <iostream>
using namespace std;

int main() {
    int N, m;
    cin >> N;
    int arr[26];
    for(int i=0; i<26; i++) {
        arr[i]=0;
    }
    string name;
    bool b = false;
    for(int i=0; i<N; i++) {
        cin >> name;
        m = (int)(name[0]-'a');
        arr[m]++;
    }
    for(int i=0; i<26; i++) {
        if(arr[i]>=5) {
            cout << (char)(i+'a');
            b = true;
        }
    }
    if(!b) cout << "PREDAJA";
}   