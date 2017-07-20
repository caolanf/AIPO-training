#include <bits/stdc++.h>

using namespace std;

vector<int> numbers = {3,2,-1,6,5,4,-3,3,7,2,3};
vector<int> binary_tree(numbers.size()+1);

int main () {
  // Creates binary indexed tree
  for (int i=0;i<numbers.size();++i) {
    int x=i+1;
    while (x<binary_tree.size()) {
      binary_tree[x] += numbers[i];
      x += x&-x;
    }
  }
  
  // Finds sum in range 0,5
  int sum_ind = 5;
  int sum = 0;
  while (sum_ind != 0) {
    sum += binary_tree[sum_ind];
    sum_ind -= sum_ind&-sum_ind;
  }
  
  // Changes element in tree
  int x=1;
  int dif=1;
  while (x<binary_tree.size()) {
    binary_tree[x] += dif;
    x += x&-x;
  }
}
