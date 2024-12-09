/*

We need a way to keep track of the empty spaces, and quickly seach through them.
Since the sizes of the empty spaces can be 1-9(can be more but will explain later), we can use a priority queue for each size.
In priority queue per size x, we will store the position of the first empty space of size x.

So, when we want to find the leftmost empty space for file size x, we can just look for the leftmost
spaces of size (x, x+1, x+2, ..., 9) in the priority queues. We will use the leftmost one.

When we change the position of the file, we will update the priority queue by removing the space.
But we need to add the remaining space if the is one, of the size emptySpace - fileSize.

Now, there can be an empty size larger than 9, since we moved a file and now empty spaces can be combined.
But that is not relevant in our case, since we are only moving files to the left, and all the remaining files are to the left of this new gap.

time complexity: O(n)
space complexity: O(n)

*/


#include <bits/stdc++.h>
using namespace std;

int arr[199990];
priority_queue<int> pqs[10];
// (pos, size)
vector<pair<int, int> > files;

int searchSpace(int size) {
  int bestLocation = 99999999;
  int bestSize = -1;
  for(int c = size; c <= 9; c++) {
    if(!pqs[c].empty()) {
      int location = -pqs[c].top();
      if(location < bestLocation) {
        bestLocation = location;
        bestSize = c;
      }
    }
  }
  
  return bestSize;

  return -1;
}

void writeChange(int emptySpacePos, pair<int, int> file) {
  for(int i = 0; i < file.second; i++) {
    int temp = arr[emptySpacePos + i];
    arr[emptySpacePos + i] = arr[file.first + i];
    arr[file.first + i] = -1;
  }
}

void printState(int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0) cout << arr[i];
        else cout << ".";
    }
    cout << "\n";
}

int main()
{
  string s;
  cin >> s;
  int currId = 0;
  int currPos = 0;
  for(int i = 0; i < s.size(); i++) {

    int num = s[i] - '0';

    if(i % 2 == 1 && num > 0) {
      pqs[num].push(-currPos);
    } else if(i % 2 == 0 && num > 0) {
      files.push_back(make_pair(currPos, num));
    }

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

  for(int i = files.size() - 1; i >= 0; i--) {
    //printState(currPos);
    int containerSize = searchSpace(files[i].second);
    if(containerSize == -1) continue;
    int emptySpacePos = -pqs[containerSize].top();
    if(emptySpacePos > files[i].first) continue;
    writeChange(emptySpacePos, files[i]);
    pqs[containerSize].pop();
    // add empty space
    int emptySpace = containerSize - files[i].second;
    if(emptySpace == 0) continue;
    pqs[emptySpace].push(-(emptySpacePos + files[i].second));
  }

  int l = 0;
  int r = s.size()-1;

  while(l < r) {
    while(arr[l] > 0 && l < s.size()) l++;
    while(arr[r] >= 0 && r >= 0) r--;
    if(l >= r) break;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    l++;
    r--;
  }

  long long checksum = 0;
  long long pos = 0;
  while(pos < currPos) {
    if(arr[pos] < 0) {
      pos++;
      continue;
    }
    checksum += pos * arr[pos];
    pos++;
  }

  cout << checksum;

  return 0;
}
