#include <iostream>
#include <string>

using namespace std;

int main() {
  string str; cin >> str;
  int i = 0, num = 1;
  string num_str = "1";

  while(i < str.size()) {
    int max_match = 0, cnt_match = 0;
    int tmp_i = i;

    for (int j=0; j<num_str.size(); j++) {
      if (tmp_i < str.size() && str[tmp_i] == num_str[j]) {
        cnt_match++;
        tmp_i++;
      }

      if (cnt_match > max_match) max_match = cnt_match;
    }

    if (max_match > 0) {
      i += max_match;
      num++;
      num_str = to_string(num);
    }
    else {
      num++;
      num_str = to_string(num);
    }
  }

  cout << num - 1;
 
  return 0;
}