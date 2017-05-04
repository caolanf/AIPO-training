#include <bits/stdc++.h>

using namespace std;

vector<int> in = { 2, 2, 1, 1, 0, 0 };
vector< vector<int> > out = { {}, {}, {3}, {1}, {0,1}, {0,2} };
deque<int> node_queue;
string ans;

int main() {
  for(int i=0; i<in.size(); ++i) {
    if(in[i] == 0) {
      node_queue.push_front(i);
    }
  }
  
  while(node_queue.size() > 0) {
    int node = node_queue.front();
    node_queue.pop_front();
      ans += ('0' + node);
      
      for(auto con_node : out[node]) {
        node_queue.push_front(con_node);
        --in[con_node];
      }
      
    }
  }
  
  cout << ans
}
