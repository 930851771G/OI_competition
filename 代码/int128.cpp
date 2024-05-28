#include <bits/stdc++.h>
using namespace std;

#define i128 __int128
const int N = 2e5+5;

void print(i128 x){
	if(x<0) cout<<"-";
	string t = "";
	
	while(x){
		t += (char) ('0' + x%10);
		x /= 10; 
	}	
	reverse(t.begin(),t.end());
	for(auto v:t) cout<<v;
	cout<<"\n";
}
signed main()
{
	int x = 10;
	i128 now = x;
	for(int i=1;i<15;i++){
		now = now*10;
	}
	long long y = now;
	cout<<y<<"\n";
	return 0;
}
