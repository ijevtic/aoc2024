#include <bits/stdc++.h>
using namespace std;

int n = 140;
char mat[140][140];
vector<vector<vector<char> > > matrices = {
    {
        {'M', '.', 'S'},
        {'.', 'A', '.'},
        {'M', '.', 'S'}
    },
    {
        {'M', '.', 'M'},
        {'.', 'A', '.'},
        {'S', '.', 'S'}
    },
    {
        {'S', '.', 'S'},
        {'.', 'A', '.'},
        {'M', '.', 'M'}
    },
    {
        {'S', '.', 'M'},
        {'.', 'A', '.'},
        {'S', '.', 'M'}
    }
};

bool detectMAS(int x, int y, int masIndex) {
  int posX = 0;
  int posY = 0;
  while(posX != 3 && x+posX >= 0 && x+posX < 140 && y+posY >= 0 && y+posY < 140) {
    if(matrices[masIndex][posX][posY] != '.' &&
        matrices[masIndex][posX][posY]!= mat[x+posX][y+posY]) break;
    
    posY++;
    if(posY == 3) {
      posX++;
      posY = 0;
    }
  }
  
  return posX == 3;
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
      for(int k = 0; k < matrices.size(); k++) {
        if(detectMAS(i, j, k))
          sol++;
      }
    }
  }
  
  cout << sol;
  
}