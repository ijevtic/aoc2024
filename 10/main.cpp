#include <bits/stdc++.h>
using namespace std;

const int n = 49;
int mat[n][n];
int mark[n][n];
bool b_flag = true;
vector<pair<int,int> > nnext = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool ok(int x, int y, int c) {
    return x >= 0 && x < n && y >= 0 && y < n && !mark[x][y] && mat[x][y] == c + 1;
}

long long dfs(int x, int y) {
    long long res = 0;
    mark[x][y] = true;
    if(mat[x][y] == 9) {
        mark[x][y] = !b_flag;
        return 1;
    }
    for(int i = 0; i < nnext.size(); i++) {
        int xN = x + nnext[i].first;
        int yN = y + nnext[i].second;
        if(!ok(xN, yN, mat[x][y])) continue;
        res += dfs(xN, yN);
    }

    mark[x][y] = !b_flag;
    return res;
}

int main()
{
  for(int i = 0; i < n; i++) {
     string s;
     cin >> s;
     for(int j = 0; j < n; j++) {
        mat[i][j] = s[j] - '0';
     }
  }
  long long res = 0;
  for(int i = 0; i < n; i++) {
     for(int j = 0; j < n; j++) {
        if(mat[i][j] != 0) continue;
        memset(mark, false, sizeof(mark));
        res += dfs(i,j);
     }
  }

  cout << res;

  return 0;
}
