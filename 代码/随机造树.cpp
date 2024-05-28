#include <bits/stdc++.h>
using namespace std;

int getrand(int x,int y){
	return rand()%(y-x+1) + x;
}
int fa[200005];
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
signed main()
{
	srand(time(0));
	int n = 10;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	int cnt = 0;
	
	
	while(cnt<n-1){
		int x = getrand(1,n);
		int y = getrand(1,n);
		
		if(find(x) == find(y)) continue;
		cout<<x<<" "<<y<<"\n";
		int fx = find(x);
		int fy = find(y);
		fa[fx] = fy;
		cnt++;
	}
	
	return 0;
}
