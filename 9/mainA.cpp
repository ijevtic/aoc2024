#include <bits/stdc++.h>
using namespace std;

int arr[199990];

int main()
{

  string s;
  cin >> s;
  int currId = 0;
  int currPos = 0;
  for(int i = 0; i < s.size(); i++) {
    int num = s[i] - '0';

    for(int j = 0; j < num; j++) {
      if(i % 2 == 0)
        arr[currPos++] = currId;
      else
        arr[currPos++] = -1;
    }

    if(num > 0 && i % 2 == 0) {
      currId++;
    }
  }

  int l = 0;
  int r = currPos-1;

  while(l < r) {
    while(arr[l] != -1 && l < currPos) l++;
    while(arr[r] == -1 && r >= 0) r--;
    if(l >= r) break;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }

  long long checksum = 0;
  long long pos = 0;
  while(pos < currPos && arr[pos] != -1) {
    checksum += pos * arr[pos];
    pos++;
  }

  cout << checksum;

  return 0;
}
