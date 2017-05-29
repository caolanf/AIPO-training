#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector <vector <int>>> nodes = { { {1,3} }, { {2,4} }, { {0,5}, {3,2} }, { {0,3} } };
  int grid[4][4];
  
  for(int i=0;i<4;++i) {
    for(int x=0;x<4;++x) {
      grid[i][x] = 100;
      if(i == x) {
        grid[i][x] = 0;
      }
    }
  }
  
  for(int i=0;i<4;++i) {
    for(int x=0;x<nodes[i].size();++x) {
      grid[i][nodes[i][x][0]] = nodes[i][x][1];
    }
  }
  
  for(int i=0;i<4;++i) {
    for(int x=0;x<4;++x) {
      for(int y=0;y<4;++y) {
        if(grid[i][x]+grid[x][y] < grid[i][y]) {
          grid[i][y] = grid[i][x]+grid[x][y];
        }
      }
    }
  }
  
  for(int i=0;i<4;++i) {
    for(int x=0;x<4;++x) {
      cout << grid[i][x] << " ";
    }
    cout << endl;
  }
}
