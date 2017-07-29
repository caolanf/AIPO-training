#include <bits/stdc++.h>

using namespace std;

class FenwichTree {
	private:
	int n;
	vector<int> ft;
	
	void update (int val, int ind) {
		for (; ind<=n+1; ind+=ind&(-ind)){ ft[ind] += val; }
	}
	
	public:
	FenwichTree (vector<int> A) { 
		n = (int)A.size();
		ft.assign(A.size()+1,0);
		for (int i=0;i<=n;++i){ update (A[i], i+1); }
		
		for (int i=0;i<=n;++i){ 
			cout << ft[i] << endl;
		}
	}
	
	int rsq(int a) {
		int sum = 0;
		for(; a>0; a-=a&(-a)) {
			sum += ft[a];
		}
		return sum;
	}
	
	int rsq(int a, int b){ return rsq(b)-rsq(a); }
	
};

int main ()
{
	vector<int> numbers = {0, 1, 0, 1, 2, 3, 2, 1, 1, 0};
	FenwichTree ft(numbers);
	cout << ft.rsq(3,6);
	return 0;
}
