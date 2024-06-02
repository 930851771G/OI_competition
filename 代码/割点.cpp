#include <bits/stdc++.h>
using namespace std;

const int M = 1e4+5;
const int N = 1e4+5;
int n, m;  // n：点数 m：边数
int dfn[5001], low[5001], inde, res;
bool vis[5001], flag[5001];  // flag: 答案 vis：标记是否重复
bool GB[M];
bool SB[M];
vector< pair<int,int> > edge[5001];        // 存图用的
int fa[5001];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
pair<int,int>E[10001];


void Tarjan(int u, int father) {  
  vis[u] = true;                  // 标记
  low[u] = dfn[u] = ++inde;  // 打上时间戳
  int child = 0;             
  for (auto v : edge[u]) { 
  	int y = v.first;
    if (!vis[y]) {
      SB[v.second] = 1;
      child++;                       
      Tarjan(y, u);                  // 继续
      low[u] = min(low[u], low[y]);  // 更新能到的最小节点编号
      if (father != u && low[y] >= dfn[u] && !flag[u]) {  
        flag[u] = true;
        res++;  // 记录答案
      }
    } else if (y != father) {  // 如果这个点不是自己，更新能到的最小节点编号
      low[u] = min(low[u], dfn[y]);
    }
  }
  if (father == u && child >= 2 && !flag[u]) {
    flag[u] = true;
    res++;  // 记录答案
  }
}



void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx == fy) return ;
	fa[fx] = fy;
}
void dfs(int R,int x,int fa){

	for(auto v:edge[x]){
		int y = v.first;
		if(y==fa) continue;
		int id = v.second;
		if(SB[id] == 0) continue;
		if(GB[id] == 1) continue;
		merge(R,y);
		dfs(R,y,x);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;     
  	for(int i=1;i<=n;i++) fa[i] = i;             
  	for (int i = 1; i <= m; i++) {  
    	int x, y;
    	cin >> x >> y;
    	E[i] = {x,y};
    	edge[x].push_back({y,i});
    	edge[y].push_back({x,i});
  	}

  	for (int i = 1; i <= n; i++)  
    if (!vis[i]) {
      inde = 0;      
      Tarjan(i, i); 
    }

    for(int i=1;i<=n;i++){
  	if(edge[i].size() == 1) flag[i]=1;
  }

  	for(int i=1;i<=m;i++){
  	int x = E[i].first;
  	int y = E[i].second;
  	if(flag[x] && flag[y]) GB[i] = 1;
  } 


  	for(int i=1;i<=n;i++){
		dfs(i,i,0);
	}

 
 	return 0;
}