#include <bits/stdc++.h>
using namespace std;

const int n = 8;

map<pair<long long, int>, long long> dp;

pair<long long,long long> takeApart(long long x) {
  int numDigits = 0;
  long long tmp = x;
  while(tmp > 0) {
    numDigits++;
    tmp /= 10;
  }

  if(numDigits % 2 != 0) return make_pair(-1, -1);
  numDigits = numDigits / 2;
  long long second = 0;
  long long degree = 1;
  while(numDigits--) {
    second = second + degree*(x%10);
    x /= 10;
    degree *= 10;
  }

  return make_pair(x, second);
}

long long solve(vector<long long> v, int k) {
  if(k == 0) {
    return v.size();
  }
  long long res = 0;
  for(int i = 0; i < v.size(); i++) {
    long long tr = 0;
    if(dp[{v[i], k}] > 0) {
      res += dp[{v[i], k}];
      continue;
    }

    if(v[i] == 0) tr += solve({1}, k-1);
    else {
      pair<long long, long long> split = takeApart(v[i]);
      if(split.first != -1) {
        tr += solve({split.first, split.second}, k-1);
      } else {
        tr += solve({v[i]*2024}, k-1);
      }
    }
    dp[{v[i], k}] = tr;
    res += tr;
  }
  return res;
}

int main() {
  long long res = 0;
  for(int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    res += solve({x}, 75);
  }

  cout << res;
  return 0;
}
