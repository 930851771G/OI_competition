#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
bool check(int x) {
}
signed main()
{
	int l = 1 ;
	int r = 1e9;
	
	while(l<r){
		int mid = (l+r+1)>>1;
		if(check(mid)) l = mid;
		else r = mid+1;
	}
	return 0;
}
