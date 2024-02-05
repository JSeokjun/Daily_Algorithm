#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string str;
    getline(cin, str);
    
    vector<char> happy = {'H', 'A', 'P', 'Y'};
    vector<char> sad = {'S', 'A', 'D'};
    double ph = 0, pg = 0;
    
    for(int i=0; i<str.size(); i++) {
        auto it = find(happy.begin(), happy.end(), str[i]); 
        if(it != happy.end()) ph++;
        
        it = find(sad.begin(), sad.end(), str[i]); 
        if(it != sad.end()) pg++;
    }
    
    double result = round(ph / (ph + pg) * 10000)/100;
    
    cout << fixed;
    cout.precision(2);
    
    if(ph==0 && pg==0) cout << 50.0;
    else cout << result;

    return 0;
}   