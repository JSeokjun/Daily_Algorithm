#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    int i = 0;
    int result = 0;
    string doc, word;
    getline(cin, doc);
    getline(cin, word);
    while (1) {
        if (i+word.length()>doc.length()) break;
        cnt = 0;
        for (int j=0; j<word.length(); j++) {
            if (doc[i+j]!=word[j]) {
                i++;
                break;
            }
            else cnt+=1;
        }
        if (cnt==word.length()) {
            result+=1;
            i+=word.length();
        }
    }
    cout << result;
}