#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i=0;
    bool b = true;
    string str;
    vector<char> v;
    cin >> str;

    if((str[0]>='A'&&str[0]<='Z') || str[0]=='_' || str[str.length()-1]=='_') {
        b = false;
        cout << "Error!";
    }
    else if(str.find('_')==string::npos) {
        for(int i=0; i<str.length(); i++) {
            if(str[i]>='A' && str[i]<='Z') {
                v.push_back('_');
                v.push_back(str[i]+32);
                continue;
            }
            v.push_back(str[i]);
        }
    }
    else {
        while(1) {
            if(i==str.length()) break;
            if((str[i]>='A' && str[i]<='Z')) {
                cout << "Error!";
                b = false;
                break;
            }
            if(str[i]=='_') {
                if((str[i+1]>='A' && str[i+1]<='Z') || str[i+1]=='_') {
                    cout << "Error!";
                    b = false;
                    break;
                }
                v.push_back(str[i+1]-32);
                i+=2;
                continue;
            }
            v.push_back(str[i]);
            i+=1;
        }
    }

    if(b) {
        for(int i=0; i<v.size(); i++) {
            cout << v[i];
        }
    }
}