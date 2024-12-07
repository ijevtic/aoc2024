#include <bits/stdc++.h>
using namespace std;

int n = 850;
long long MAX = 100000000000000000;

bool b_flag = true;

long long combine(long long a, long long b) {
    long long degree = 1;
    long long bhelp = b;
    while(bhelp > 0) {
        bhelp /= 10;
        a *= 10;
        if(a > MAX)
            return MAX;
    }
    return a + b;
}

bool rec(int i, long long curr, long long num, vector<long long> nums) {
    if(i > nums.size()) {
        return false;
    }
    if(i == nums.size()) {
        return num == curr;
    }

    if(curr > num) return false;
    if(curr * nums[i] <= num) {
        if(rec(i+1, curr * nums[i], num, nums))
            return true;
    }
    if(curr + nums[i] <= num) {
        if(rec(i+1, curr + nums[i], num, nums))
            return true;
    }
    long long combo = combine(curr, nums[i]);
    if(b_flag && combo <= num) {
        if(rec(i+1, combo, num, nums))
            return true;
    }

    return false;
}

bool valid(long long num, vector<long long> nums) {
    return rec(0, 0, num, nums);
}

int main() {
  long long res = 0;

  for(int i = 0; i < n; i++) {
    cout << i << "\n";
    int len;
    cin >> len;
    long long num;
    cin >> num;
    vector<long long> nums;
    for(int j = 0; j < len-1; j++) {
        long long x;
        cin >> x;
        nums.push_back(x);
    }

    if(valid(num, nums)) res += num;

  }

  cout << res;
}
