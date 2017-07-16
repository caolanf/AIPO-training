#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector <vector <signed int>>> nodes = { {{1,8},{2,10}}, {{3,1}}, {{4,2}}, {{2,-4},{4,-1}}, {{5,-2}},{{2,1}} };
  int dist[nodes.size()];
  
  fill(dist, dist+sizeof(dist), 100);
  dist[0] = 0;
  
  for(int y=0;y<nodes.size();++y){
    for(int i=0;i<nodes.size();++i) {
  	  for(int x=0;x<nodes[i].size();++x) {
  	    if(dist[nodes[i][x][0]] > dist[i]+nodes[i][x][1]) {
  		    dist[nodes[i][x][0]] = dist[i]+nodes[i][x][1];
  	    }
  	  }
    }
  }
  
  for(int i=0;i<nodes.size();++i) {
	  cout << dist[i] << endl;
  }
  
}
