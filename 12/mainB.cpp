// I counted all the corners that the shape has, and that is the number of corners
// case A
//  X
//  AX

// case B
//  AX
//  AA

#include <bits/stdc++.h>
using namespace std;

const int n = 140;
char mat[n][n];
bool mark[n][n];
vector<pair<int,int> > diff = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0},
};

int currSize = 0;
bool ok(int x, int y, char c) {
  return x >= 0 && y >= 0 && x < n && y < n && mat[x][y] == c;
}

bool ok(int x, int y, int c, pair<int,int> diff) {
  int xr = x + diff.first;
  int yr = y + diff.second;
  return ok(xr, yr, c);
}

bool checkEdge(int x, int y, int c, pair<int, int> n1, pair<int,int> n2) {
  pair<int, int> n3 = make_pair(n1.first + n2.first, n1.second + n2.second);
  
  return (!ok(x,y,c,n1) && !ok(x,y,c,n2)) 
  || (ok(x,y,c,n1) && ok(x,y,c,n2) && !ok(x,y,c,n3));
}

int numEdges(int x, int y) {
  int cnt = 0;
  for(int i = 0; i < diff.size(); i++)
    cnt += checkEdge(x, y, mat[x][y], diff[i], diff[(i+1)%4]) ? 1 : 0;
  
  return cnt;
}

pair<long long, long long> findShape(int x, int y) {
  currSize++;
  mark[x][y] = true;
  int cnt = 1;
  int edges = numEdges(x,y);
  for(int i = 0; i < diff.size(); i++) {
    int xr = x + diff[i].first;
    int yr = y + diff[i].second;
    if(!ok(xr, yr, mat[x][y])) continue;
    if(mark[xr][yr]) continue;
    pair<int,int> res = findShape(xr,yr);
    cnt += res.first;
    edges += res.second;
  }
  
  return make_pair(cnt, edges);
}

int main() {
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j++) {
      mat[i][j] = s[j];
    }
  }
  
  long long res = 0;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!mark[i][j]) {
        currSize = 0;
        pair<long long, long long> shape = findShape(i,j);
        res += shape.first * shape.second;
      }
    }
  }
  
  cout << res;
}