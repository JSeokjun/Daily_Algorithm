#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    int sum1=0, sum2=0;
    if(a.length()!=b.length()) return a.length()<b.length();
    else {
        for(int i=0; i<a.length(); i++) {
            if(a[i]>='0' && a[i]<='9') {
                sum1+=(a[i]-'0');
            }
        }
        for(int i=0; i<b.length(); i++) {
            if(b[i]>='0' && b[i]<='9') {
                sum2+=(b[i]-'0');
            }
        }
        if(sum1!=sum2) return sum1 < sum2;
        else return a < b;
    }
}

int main() {
    int N;
    cin >> N;
    string str;
    vector<string> v;
    for(int i=0; i<N; i++) {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<N; i++) {
        cout << v[i] << '\n';
    }
}