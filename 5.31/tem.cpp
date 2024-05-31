#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 3e4+5;
int ma[N<<2];
int sum[N<<2];
int n;
int w[N];
vector<int>tr[N];
int dep[N],son[N],fa[N],sz[N];


void dfs1(int x,int F){
	fa[x] = F;
	sz[x] = 1;
	dep[x] = dep[F]+1;

	int max_son = -1;
	for(auto v:tr[x]){
		if(v==F) continue;
		dfs1(v,x);
		sz[x] += sz[v];
		if(sz[v] > max_son) max_son = sz[v], son[x] = v;
	}
}

int id[N],wt[N],top[N];
int cnt = 0;

void dfs2(int x,int topf){
	id[x] = ++cnt;
	wt[cnt] = w[x];
	top[cnt] = topf;
	if(son[x]) dfs2(son[x] , topf);
	for(auto v:tr[x]){
		if(v==son[x] || v==fa[x]) continue;
		dfs2(v,v);
	}
}

void build1(int k,int l,int r){
	if(l==r) {
		ma[k] = wt[l];
		return ;
	}
	int mid = (l+r)>>1;
	build1(2*k,l,mid);
	build1(2*k+1,mid+1,r);
	ma[k] = max(ma[2*k],ma[2*k+1]);
}

void build2(int k,int l,int r){
	if(l == r){
		sum[k] = wt[l];
		return ;
	}
	int mid = (l+r)>>1;
	build2(2*k,l,mid);
	build2(2*k+1,mid+1,r);
	sum[k] = sum[2*k] + sum[2*k+1];
}



void change1(int k,int l,int r,int pos,int val){
	if(l==r){
		ma[k] = val;
		return ;
	}
	int mid = (l+r)>>1;
	if(pos<=mid) change1(2*k,l,mid,pos,val);
	else change1(2*k+1,mid+1,r,pos,val);
	ma[k] = max(ma[2*k],ma[2*k+1]);
}

void change2(int k,int l,int r,int pos,int val){
	if(l==r){
		sum[k] = val;
		return ;
	}
	int mid = (l+r)>>1;
	if(pos<=mid) change2(2*k,l,mid,pos,val);
	else change2(2*k+1,mid+1,r,pos,val);
	sum[k] = sum[2*k] + sum[2*k+1];
}

int query_ma(int k,int l,int r,int pos){
	if(l == r) return ma[k];
	int mid = (l+r)>>1;
	if(pos<=mid) return query_ma(2*k,l,mid,pos);
	else return query_ma(2*k+1,mid+1,r,pos);
}

int query_sum(int k,int l,int r,int pos){
	if(l == r) return sum[k];
	int mid = (l+r)>>1;
	if(pos<=mid) return query_sum(2*k,l,mid,pos);
	else return query_sum(2*k+1,mid+1,r,pos);
}

int query1(int k,int l,int r,int x,int y){
	if(x<=l && r<=y){
		return ma[k];
	}
	int mid =(l+r)>>1;
	int maxa = (int)-100000000000;
	if(x<=mid) maxa = max(maxa,query1(2*k,l,mid,x,y));
	if(y>mid) maxa = max(maxa,query1(2*k+1,mid+1,r,x,y));
	return maxa;
}

int query2(int k,int l,int r,int x,int y){
	if(x<=l && r<=y){
		return sum[k];
	}
	int mid =(l+r)>>1;
	int ans = 0;
	if(x<=mid) ans += query2(2*k,l,mid,x,y);
	if(y>mid) ans += query2(2*k+1,mid+1,r,x,y);
	// cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<ans<<"\n";
	return ans;
}



int lca1(int x,int y){
	int ans = -100000000;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans = max(ans,query1(1,1,n,id[top[x]],id[x]));
		x = top[x];
		x = fa[x];
	}
	if(dep[x] > dep[y]) swap(x,y);
	ans = max(ans,query1(1,1,n,id[x],id[y]));
	return ans;
}

int lca2(int x,int y){
	int ans = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans += query2(1,1,n,id[top[x]],id[x]);
		// x = top[x];
		// if(dep[x] < dep[y]) swap(x,y);
		x = fa[top[x]];
	}
	// if(x==y) return ans;
	if(dep[x] > dep[y]) swap(x,y);
	ans += query2(1,1,n,id[x],id[y]);
	return ans;
}

void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y; cin>>x>>y;
		tr[x].push_back(y);
		tr[y].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>w[i];

	dfs1(1,0);
	dfs2(1,1);
	build1(1,1,n);
	build2(1,1,n);

	int q; 
	cin>>q;

	while(q--){
		string s;
		cin>>s;
		if(s=="QMAX"){
			int x,y;
			cin>>x>>y;
			cout<<lca1(x,y)<<"\n";
			// continue;
		}

		if(s == "CHANGE"){
			int x,y; cin>>x>>y;
			change1(1,1,n,id[x],y);
			change2(1,1,n,id[x],y);
			// continue;
		}

		if(s=="QSUM"){
			int x,y; cin>>x>>y;
			cout<<lca2(x,y)<<"\n";
		}

		// for(int i=1;i<=n;i++){
		// 	cerr<<query_ma(1,1,n,i)<<" \n"[i==n];
		// }
		// for(int i=1;i<=n;i++){
		// 	cerr<<query_sum(1,1,n,i)<<" \n"[i==n];
		// }
	}
}

signed main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	solve();
	return 0;
}