#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  set<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'n', 'm', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

  while(1) {
    string password; cin >> password;
    int vowel_seq_cnt = 0, cons_seq_cnt = 0;
    bool last_vowel = false, is_accept = true, exist_vowel = false;

    if (password == "end") break;

    if (vowels.find(password[0]) != vowels.end()) {
      vowel_seq_cnt++;
      last_vowel = true;
      exist_vowel = true;
    }
    else cons_seq_cnt++;

    for (int i=1; i<password.length(); i++) {
      
      if (password[i-1] == password[i] && password[i] != 'e' && password[i] != 'o') {
        is_accept = false;
        break;
      }

      if (vowels.find(password[i]) != vowels.end() && last_vowel) {
        vowel_seq_cnt++;
        exist_vowel = true;
      }
      else if (vowels.find(password[i]) != vowels.end() && !last_vowel){
        vowel_seq_cnt++;
        cons_seq_cnt = 0;
        last_vowel = true;
        exist_vowel = true;
      }
      else if (consonants.find(password[i]) != consonants.end() && !last_vowel){
        cons_seq_cnt++;
      }
      else if (consonants.find(password[i]) != consonants.end() && last_vowel){
        cons_seq_cnt++;
        vowel_seq_cnt = 0;
        last_vowel = false;
      }

      if (vowel_seq_cnt == 3 || cons_seq_cnt == 3) {
        is_accept = false;
        break;
      }
    }

    if (is_accept && exist_vowel) {
      cout << '<' << password << '>' << " is acceptable." << '\n';
    }
    else {
      cout << '<' << password << '>' << " is not acceptable." << '\n';
    }
  }

  return 0;
}