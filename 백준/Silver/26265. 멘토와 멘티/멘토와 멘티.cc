#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    string mentor1 = a.substr(0, a.find(' '));
    string mentor2 = b.substr(0, b.find(' '));
    
    if (mentor1 != mentor2)
        return mentor1 < mentor2;
    
    string mentee1 = a.substr(a.find(' ')+1);
    string mentee2 = b.substr(b.find(' ')+1);
    
    return mentee1 > mentee2;
}

int main() {
    int N;
    string str;
    vector<string> v;
    cin >> N;
    cin.ignore();
    
    for(int i = 0; i < N; i++) {
        getline(cin, str);
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }
    
    return 0;
}
