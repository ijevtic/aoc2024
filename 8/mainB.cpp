#include <bits/stdc++.h>
using namespace std;

const int n = 50;
char mat[n][n];
unordered_map<char, vector<pair<int,int> > > points;
bool mark[n][n];

bool markPoint(int i, int j) {
  if(i < 0 || i >= n || j < 0 || j >= n) return false;
  mark[i][j] = true;
  return true;
}

void markAllPoints(int p1, int sign1, int add1, int p2, int sign2, int add2) {
    int k = 1;
    while(markPoint(p1 + k*sign1*add1, p2 + k*sign2*add2)) {
        k++;
    }

    k = 1;
    sign1 *= -1;
    sign2 *= -1;
    while(markPoint(p1 + k*sign1*add1, p2 + k*sign2*add2)) {
        k++;
    }
}

void findPoints(vector<pair<int,int> > pos) {
  for(int i = 0; i < pos.size(); i++) {
    for(int j = i + 1; j < pos.size(); j++) {
      int diffA = pos[j].first - pos[i].first;
      int diffB = pos[j].second - pos[i].second;
      markPoint(pos[i].first, pos[i].second);
      markPoint(pos[j].first, pos[j].second);
      if(diffA > 0) {
        markAllPoints(pos[i].first, -1, diffA, pos[i].second, -1, diffB);
      } else {
        markAllPoints(pos[j].first, -1, diffA, pos[j].second, -1, diffB);
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
