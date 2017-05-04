#include <bits/stdc++.h>

using namespace std;

struct distSort {
  bool operator()(vector<int> lhs, vector<int> rhs) const {
    return lhs[1] < rhs[1];
  }
};
priority_queue<vector<int>, vector< vector<int> >, distSort> node_dist;
vector<vector<vector<int>>> edges = { { {1,5}, {2,7} }, { {3,8} }, { {3,9} }, { {4,3} }, {} };
vector<int> node_dist2 = {0, 100000, 100000, 100000, 100000};

int main() {
  node_dist.push({0,0});
  
  while(node_dist.size() > 0) {
    vector<int> node = node_dist.top();
    node_dist.pop();
    
    for(auto edge : edges[node[0]]) {
      if(node_dist2[node[0]]+edge[1] < node_dist2[edge[0]]) {
         node_dist2[edge[0]] = node_dist2[node[0]]+edge[1];
         node_dist.push({edge[0],node_dist2[edge[0]]});
      }
    }
    
  }
  
  cout << node_dist2[4];
}
