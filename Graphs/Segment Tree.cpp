#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
	private: 
	vector<int> st, A;
	int n;
	int left (int p) { return p << 1; }
	int right (int p) { return (p << 1)+1; }
	
	void build (int p, int L, int R) {
		if (L == R)
			st[p] = L;
		else {
			build (left(p), L, (L+R)/2);
			build (right(p), (L+R)/2 +1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}
	
	void update (int p, int L, int R, int i, int new_val) {
		if (!(i > R || i < L)) {
			if (L == R)
				st[p] = L;
			else {
				update (left(p), L, (L+R)/2, i, new_val);
				update (left(p), (L+R)/2+1, R, i, new_val);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = (A[p1] <= A[p2]) ? p1 : p2;
			}
		}
	}
	
	int rmq (int p, int L, int R, int i, int j) {
		if (i > R || j < L ) return -1;     // Out of scope
		if (L >= i && R <= j) return st[p]; // Inside query range
		
		int p1 = rmq (left(p), L, (L+R)/2, i, j);
		int p2 = rmq (right(p), (L+R)/2 + 1, R, i, j);
		
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		
		return (A[p1] <= A[p2]) ? p1 : p2;
	}
	
	public:
	SegmentTree (const vector<int> &_A) {
		A = _A;
		n = (int)A.size();
		st.assign(4*n,0);
		build(1, 0, n-1);
	}
	
	int rmq (int i, int j) { return rmq(1, 0, n-1, i, j); }
	void update (int i, int new_val) { A[i] = new_val; update(1, 0, n-1, i, new_val); }
};

int main()
{
	vector<int> numbers = {5,3,7,2,1,9};
	SegmentTree st(numbers);
	
	cout << "RMQ(1,5) : " << st.rmq(1,5) << endl;
	st.update(2,0);
	cout << "New min : " << st.rmq(0,5) << endl;
}
