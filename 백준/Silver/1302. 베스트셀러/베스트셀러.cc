#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, cnt, sum=0;
    cin >> n;
    string s, result;
    vector<string> v;
    for(int i=0; i<n; i++) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    s="";
    for(int i=0; i<n; i++) {
        if(s!=v[i]) {
            cnt=0;
            s=v[i];
        }
        cnt++;
        if(cnt>sum) {
            sum=cnt;
            result=v[i];
        }
    }
    cout << result;
}