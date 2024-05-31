#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 3e4+5;
int n; 
vector<int>tr[N];
int w[N],cnt;

int dep[N],sz[N],fa[N],son[N];
void dfs1(int x,int F){
	dep[x] = dep[F]+1;
	sz[x] = 1;
	fa[x] = F;
	int max_son = -1;
	for(auto v:tr[x]){
		if(v==F) continue;
		dfs1(v,x);
		sz[x] += sz[v];
		if(sz[v]>max_son) son[x] = v,max_son = sz[v];
	}
}

int top[N],id[N],wt[N];
void dfs2(int x,int topf){
	top[x] = topf;
	id[x] = ++cnt;
	wt[cnt] = w[x];
	if(son[x]) dfs2(son[x],topf);
	for(auto v:tr[x]){
		if(v==fa[x] || v==son[x]) continue;
		dfs2(v,v);
	}
}

int tr1[N<<2],tr2[N<<2];

void build(int k,int l,int r){
	if(l==r){
		tr1[k] = wt[l];
		tr2[k] = wt[l];
		return ;
	} 
	int mid = (l+r)>>1;
	build(2*k,l,mid);
	build(2*k+1,mid+1,r);
	tr1[k] = max(tr1[2*k],tr1[2*k+1]);
	tr2[k] = tr2[2*k] + tr2[2*k+1];
}

int query1(int k,int l,int r,int x,int y){
	if(x<=l && r<=y) return tr1[k];
	int mid = (l+r)>>1;
	int maxa = -1e10;
	if(x<=mid) maxa = max(maxa,query1(2*k,l,mid,x,y));
	if(y>mid) maxa = max(maxa,query1(2*k+1,mid+1,r,x,y));
	return maxa;
}
int query2(int k,int l,int r,int x,int y){
	if(x<=l && r<=y) return tr2[k];
	int mid = (l+r)>>1;
	int ans = 0;
	if(x<=mid) ans+= query2(2*k,l,mid,x,y);
	if(y>mid) ans+= query2(2*k+1,mid+1,r,x,y);
	return ans;
}

void change(int k,int l,int r,int pos,int val){
	if(l==r){
		tr1[k] = tr2[k] = val;
		return ;
	}
	int mid = (l+r)>>1;
	if(pos<=mid) change(2*k,l,mid,pos,val);
	if(pos>mid) change(2*k+1,mid+1,r,pos,val);
	tr1[k] = max(tr1[2*k],tr1[2*k+1]);
	tr2[k] = tr2[2*k] + tr2[2*k+1];
}


int lca(int x,int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		x = top[x];
		x = fa[x];
	}
	if(x==y) return x;
	if(dep[x] > dep[y]) swap(x,y);
	return x;
}

int lca1(int x,int y){
	int maxa = -1e10;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		maxa = max(maxa,query1(1,1,n,id[top[x]],id[x]));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	maxa = max(maxa,query1(1,1,n,id[x],id[y]));
	return maxa;
}
int lca2(int x,int y){
	int ans = 0;
	while(top[x]!= top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans += query2(1,1,n,id[top[x]],id[x]);
		x = fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
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

	build(1,1,n);
	int q; cin>>q;
	while(q--){
		string s; cin>>s;
		// cerr<<s<<"\n";
		if(s=="QMAX"){

			int x,y; cin>>x>>y;
			cout<<lca1(x,y)<<"\n";
		}else {
			if(s=="QSUM"){
				int x,y; cin>>x>>y;
				cout<<lca2(x,y)<<"\n";
			} else{
				int x,y; cin>>x>>y;
				change(1,1,n,id[x],y);
			}

		}
	}
}


signed main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	solve();
	return 0;
}