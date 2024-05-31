#include <bits/stdc++.h>
using namespace std;


const int N = 2e5+6;
int fa[N];
int val[N];
int find(int x){
	if(fa[x] == x) return x;
	int t = fa[x];
	fa[x] = find(fa[x]);
	val[x] += val[t];
}
void merge(int x,int y,int s){
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
	val[fx] = val[y] + s - val[x];
}
signed main()
{
	return 0;
}