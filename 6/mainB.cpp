#include <bits/stdc++.h>
using namespace std;

int n = 130;
pair<int,int> start;
pair<int,int> curr;
int mat[130][130];
map<pair<int, pair<int,int> >, bool> mark;
int currDir = 1;
vector<pair<int, int> > diff = {
  {0, -1},
  {-1, 0},
  {0, 1},
  {1, 0}
};

bool leave(pair<int,int> pos) {
  return pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= n;
}

bool taken(pair<int,int> pos) {
  return mat[pos.first][pos.second] == -1;
}

// 0 - go on
// -1 - got out
// 1 - stuck in a loop
int move() {
  if(mark[make_pair(currDir, curr)])
    return 1;
  mark[make_pair(currDir, curr)] = true;

  pair<int, int> nextCurr = make_pair(curr.first + diff[currDir].first, curr.second + diff[currDir].second);
  if(leave(nextCurr)) {
    return -1;
  }

  if(taken(nextCurr)) {
    currDir = (currDir + 1) % 4;
    return 0;
  }

  curr = nextCurr;
  return 0;
}

int main() {

  if (!freopen("read.txt", "r", stdin)) {
    cerr << "Error: Unable to open file read.txt" << endl;
    return 1;
  }

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j++) {
      if(s[j] == '#')
        mat[i][j] = -1;
      if(s[j] == '^') {
        start = curr = make_pair(i, j);

      }
    }
  }

  int res = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(mat[i][j] == -1 || (i == start.first && j == start.second))
        continue;

      mat[i][j] = -1;
      curr = start;
      mark.clear();
      currDir = 1;
      while(true) {
        int output = move();
        if(output == 0) continue;
        if(output == -1) break;
        if(output == 1) {
          res++;
          break;
        }
      }

      mat[i][j] = 0;
    }
  }



  cout << res;

}