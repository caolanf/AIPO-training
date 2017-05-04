#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > nodes;
vector<bool> visited;
vector<int> ans;

void dfs(int u) {
  if(visited[u]) return;
  visited[u] = true;
  for(int node : nodes[u]) {
    dfs(node);
  }
  ans.push_back(u);
}

int main() {
  for(int i=0; i<nodes.size(); ++i) {
    dfs(i);
  }
  reverse(ans.begin(),ans.end());
}
