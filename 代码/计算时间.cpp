#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;


signed main()
{
	clock_t start,end;
	start = clock();
	int ans = 0;
	for(int i=1;i<=1e9;i++){
		int now =  i*i;
		ans += now;
	}
	end = clock();
	double now = end - start;
	now = now / (1000.0);
	cout<<now<<"\n";
	return 0;
}
