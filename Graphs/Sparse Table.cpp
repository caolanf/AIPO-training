#include <bits/stdc++.h>

using namespace std;

vector<int> nums = {1,2,3,4,5};
vector<vector<int>> st;

int rmq(int x, int y) {
	int len = pow(2,(int)log2(y-x));
	return min(st[log2(len)][x],st[log2(len)][y-len]);
}

int main() {
	st.push_back(nums);
	
	for(int p=2;p<=(int)nums.size();p*=2) {
		st.push_back({});
		int pi = log2(p);
		for(int i=0;i<(int)nums.size()-p+1;++i) {
			int a = st[pi-1][i];
			int b = st[pi-1][i+(int)(p/2)];
			st[pi].push_back(min(a,b));
		}
	}
}
