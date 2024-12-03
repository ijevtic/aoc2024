#include <bits/stdc++.h>
using namespace std;

char arr[20000];
int n;

bool try_read_mul(int pos) {
  if(pos+3 < n && arr[pos] == 'm' && arr[pos+1] == 'u' && arr[pos+2] == 'l' && arr[pos+3] == '(')
    return true;
  return false;
}

pair<bool, pair<long long, int> > try_read_num(int pos, char last_ch) {
  long long number = 0;
  bool started = true;
  bool valid = false;
  while(pos < n) {
    if(arr[pos] == last_ch) break;
    if(arr[pos] >= '0' && arr[pos] <= '9') {
      number = number * 10 + (long long)(arr[pos] - '0');
    } else {
      valid = false;
      break;
    }
    pos++;
    valid = true;
  }
  return make_pair(valid, make_pair(number, pos));
}

bool try_read_code(int pos, string code) {
  int cnt = 0;
  while(pos < n && cnt < code.size()) {
    if(code[cnt++] != arr[pos++]) return false;
  }
  return true;
}

int main() {
  char c;
  int state_machine = 0;
  // 0 - invalid
  // 1 - mul(
  // 2 - first_num,
  // 3 - second_num)
  n = 0;
  while (cin.get(c)) {
    arr[n++] = c;
  }
  long long first_num = 0;
  long long second_num = 0;
  long long solution = 0;
  bool is_b_flag = true;
  for(int i = 0; i < n; i++) {
   
    if(is_b_flag) {
      if(try_read_code(i, "do()")) {
        state_machine = 0;
        i += 3;
        continue;
      }
      if(try_read_code(i, "don't()")) {
        state_machine = -1;
        i += 6;
        continue;
      }   
    }
   
    if(state_machine == 0) {
      if(try_read_mul(i)) {
        i += 3;
        state_machine = 1;
      } else {
        continue;
      }
    } else if(state_machine == 1) {
      pair<bool, pair<long long, int> > res = try_read_num(i, ',');
      if(!res.first) {
        state_machine = 0;
        i--;
        continue;
      }
      state_machine = 2;
      first_num = res.second.first;
      i = res.second.second;
    } else if(state_machine == 2) {
      pair<bool, pair<long long, int> > res = try_read_num(i, ')');
      if(!res.first) {
        state_machine = 0;
        i--;
        continue;
      }
      state_machine = 0;
      second_num = res.second.first;
      i = res.second.second;
      solution += first_num * second_num;
    }
  }
 
  // depending on the value is_b_flag, result is for 3a or 3b
  cout << solution;
}