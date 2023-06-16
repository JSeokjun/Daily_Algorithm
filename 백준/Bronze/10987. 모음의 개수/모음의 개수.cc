#include <iostream>
using namespace std;

int countVowel(string w) {
    int cnt=0;
    for(int i=0; i<=w.length(); i++) if(w[i]=='a' || w[i]=='e' || w[i]=='i' || w[i]=='o' || w[i]=='u') cnt++;
    return cnt;
}
int main() {
    string word;
    cin >> word;
    cout << countVowel(word);
}