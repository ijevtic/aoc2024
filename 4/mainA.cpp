#include <bits/stdc++.h>
using namespace std;

int n = 140;
char mat[140][140];
vector<pair<int,int> > directions = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

bool searchDirection(int x, int y, int diffX, int diffY) {
  int br = 0;
  string pattern = "XMAS";
  while(br < pattern.size() && x >= 0 && x < n && y >= 0 && y < n) {
    if(pattern[br] != mat[x][y]) break;
    
    x += diffX;
    y += diffY;
    br++;
  }
  
  return br == 4;
}

int main() {
  
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < s.size(); j++) {
      mat[i][j] = s[j];
    }
  }
  long long sol = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < directions.size(); k++) {
        if(searchDirection(i, j, directions[k].first, directions[k].second))
          sol++;
      }
    }
  }
  
  cout << sol;
  
}