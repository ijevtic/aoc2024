#include <bits/stdc++.h>
using namespace std;

const int n = 50;
char mat[n][n];
unordered_map<char, vector<pair<int,int> > > points;
bool mark[n][n];

void markPoint(int i, int j) {
  if(i < 0 || i >= n || j < 0 || j >= n) return;
  mark[i][j] = true;
}

void findPoints(vector<pair<int,int> > pos) {
  for(int i = 0; i < pos.size(); i++) {
    for(int j = i + 1; j < pos.size(); j++) {
      int diffA = pos[j].first - pos[i].first;
      int diffB = pos[j].second - pos[i].second;
      if(diffA > 0) {
        markPoint(pos[j].first + diffA, pos[j].second + diffB);
        markPoint(pos[i].first - diffA, pos[i].second - diffB);
      } else {
        markPoint(pos[i].first + diffA, pos[i].second + diffB);
        markPoint(pos[j].first - diffA, pos[j].second - diffB);
      }
    }
  }
}

int main()
{
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j++) {
      mat[i][j] = s[j];
      if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')) {
        points[s[j]].push_back(make_pair(i,j));
      }
    }
  }

  for (const auto& [key, value] : points) {
    findPoints(value);
  }

  int res = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(mark[i][j]) res++;
    }
  }

  cout << res;

  return 0;
}
