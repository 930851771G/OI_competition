#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int getrand(int x,int y){
	return rand() % (y - x + 1) + x;
}
int fa[N];
int find(int x){
	if(fa[x] == x)return x;
	else return fa[x] = find(fa[x]);
}
int get_tr(){
	int n = 20;
	
	for(int i=1;i<=n;i++) fa[i] = i;
	int cnt = 0;
	while(cnt<n-1){
		int x = getrand(1,n);
		int y = getrand(1,n);
		int fx = find(x);
		int fy = find(y);
		if(fx == fy) continue;
		cnt++;
		cout<<x<<" "<<y<<"\n";
		fa[fx] = fy;
	} 
	
}


signed main()
{
	srand(time(0));
	get_tr();
	return 0;
}
