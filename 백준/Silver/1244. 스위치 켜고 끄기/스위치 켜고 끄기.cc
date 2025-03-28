#include <iostream>
#include <vector>

using namespace std;

int main() {

  int switch_len, student_num;
  vector<bool> switch_arr; 
  switch_arr.push_back(-1);

  cin >> switch_len;
  for (int i=0; i<switch_len; i++) {
    bool status; cin >> status;
    switch_arr.push_back(status);
  }
  cin >> student_num;

  for (int i=0; i<student_num; i++) {
    int gender, num;
    cin >> gender >> num;

    if (gender == 1) {
      for (int j=1; j*num<=switch_len; j++) {
        switch_arr[j*num] = switch_arr[j*num] ^ 1; 
      }
    }
    else if (gender == 2) {
      int cnt = 1;
      switch_arr[num] = switch_arr[num] ^ 1;

      while (num - cnt >= 1 && num + cnt <= switch_len) {
        if (switch_arr[num-cnt] == switch_arr[num+cnt]) {
          switch_arr[num-cnt] = switch_arr[num-cnt] ^ 1;
          switch_arr[num+cnt] = switch_arr[num+cnt] ^ 1;
          cnt++;
        }
        else {
          break;
        }
      }
    }
  }

  for (int i=1; i<switch_len+1; i++) {
    cout << switch_arr[i] << ' ';
    if (i % 20 == 0) cout << '\n';
  }

  return 0;
}