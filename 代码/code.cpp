/*
数字转换为字符串 to_string
字符串转换为数字 int now = atoi(s.c_str())
*/



/*
时间函数！
只需要 clock_t start end;
start = clock(); 最后 end = clock();
end - start  /1000 就是时间。
*/
// #include <bits/stdc++.h>
// using namespace std;
// int main(){

// 	clock_t start,end;
// 	start = clock();

// 	int ans;
// 	for(int i=1;i<=1000000000;i++){
// 		int x = i;
// 		ans+= x*x;
// 	}
// 	end = clock();
// 	cout<<end<<" "<<start<<"\n";
// 	double time = (double) (end-start) / CLOCKS_PER_SEC;
// 	cout<<time<<"\n";
// 	return 0;
// }
/* __int128的使用

声明 #define i128 __int128
输出的时候 一位一位输出就好了。
*/

/*

#include <bits/stdc++.h>
using namespace std;

#define i128 __int128
void print(i128 x){
	if(x<0) cout<<"-";
	string s = "";
	while(x){
		int now = x%10;
		s += (char) now + '0';
	}
	for(int i = s.size()-1 ;i >= 0;i--){
		cout<<s[i]<<"\n";
	}
}
int main(){

	i128 x = 1;
	for(int i=1;i<=40;i++){
		x*=10;
	}
	print(x);
	return 0;
}

*/



/* 二分 模版 
就是 l = mid 的时候 int mid = (l+r+1) >> 1;
*/


/* 三分模板
int lmid = l+(r-l)/3;
int rmid = r-(r-l)/3;
如果 lmid 比较垃圾 l = lmid +1;
如果 rmid 比较垃圾 r = rmid -1;
如果是小数 没有 +-1. 
*/



/* 数论*/
/*
快速幂 gcd 组合数 C(n,m) 逆元 质因数 
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long 

// const int mod = 998244353;
// int qmi(int a,int b){
// 	int res = 1;
// 	while(b){
// 		if(b&1) res *= a,res%=mod;
// 		a = a*a %mod;
// 		b>>=1;
// 	}
// }
// int fac[105],inv[105];
// int init(){
// 	fac[0]=1;
// 	for(int i =1 ;i<=100;i++) fac[i] = fac[i-1] * i % mod;
// 	inv[100] = qmi(fac[100],mod-2);
// 	for(int i = 100-1 ; i>=1 ; i-- ){
// 		inv[i] = inv[i+1] * (i+1) % mod;
// 	}
// }
// int C(int x,int y){
// 	if(x<y) return 0;
// 	return fac[x]*inv[y]%mod*inv[x-y]%mod;
// }

// void cal(int x){
// 	vector<int>ans;
// 	//存储x的所有的质因数 x<=1e9;
// 	for(int i=2;i*i<=x;i++){
// 		if(x%i==0){
// 			ans.push_back(i);
// 			while(x%i==0) x/=i;
// 		}
// 	}
// 	if(x>1) ans.push_back(x);
// }
// // vector<int>f;
// signed main()
// {
// 	return 0;
// }



//带权并查集。

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5+6;
// int n;
// int fa[N],val[N];

// int find(int x){
// 	if(fa[x] == x) return x;
// 	int t = fa[x];
// 	int root = find(fa[x]);
// 	val[x] += val[t];
// 	return fa[x] = root;
// }
// void merge(int x,int y,int s){
// 	int fx = find(x);
// 	int fy = find(y);
// 	fa[fx] = fy;
// 	val[fx] = (val[y]+s-val[x]);
// }
// signed main(){
// 	return 0;
// }



//优先队列:

// #include<bits/stdc++.h>
// using namespace std;

// priority_queue<int,vector<int>,greater<int> >q1;
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;

// struct node{
// 	int id,dis;
// 	bool operator < (const node & k) const{
// 		return dis>k.dis;
// 	}
// };

// priority_queue<node>q3;
// signed main()
// {
// 	return 0;
// }


//vector初始化：
// vector<vector<int>>tr(n,vector<int>(m+10));

//set:
// s.begin() 第一个 
// s.end() 最后一个的下一个 
// s.rbegin() 反向第一个 正向 最后一个

// #include <iostream>
// #include <set>
// using namespace std;

// int main()
// {
// 	set<int> i;
// 	i.insert(77);
// 	i.insert(13);
// 	i.insert(88);
// 	i.insert(55);
// 	i.insert(22);

// 	auto it1 = i.lower_bound(98);
// 	if(it1 == i.end()) {
// 		//就是 没有 找到。
// 	}
// 	cout<<*it1<<"\n";

// 	// auto it = i.begin();
// 	// for( ; it!=i.end() ;it++){
// 	// 	cout<<(*it)<<"\n";
// 	// }
// 	// auto it2 = i.rbegin();
// 	// for( ; it2!=i.rend() ;it2++){
// 	// 	cout<<(*it2)<<"\n";
// 	// }
//    return 0;
// }

//树状数组 线段树  倍增
// int lowbit(int x) {
// 	return x&(-x);
// }
// void add(int x,int val){
// 	while(x<=n){
// 		tr[x]+=val;
// 		x+=lowbit(x);
// 	}
// }
// int que(int x){
// 	int sum=0;
// 	while(x){
// 		sum+=tr[x];
// 		x-=lowbit(x);
// 	}
// }


// //倍增：
// #include <bits/stdc++.h>
// using namespace std;

// const int N =2e5+6;
// int f[N][30];int dep[N],dis[N];
// vector<int>tr[N];
// void dfs(int x,int fa){
// 	f[x][0]=fa;
// 	for(int i =1;i<=20;i++){
// 		f[x][i] = f[f[x][i-1]][i-1];
// 	}
// 	for(auto v:tr[x]){
// 		if(v== fa) continue;
// 		dep[v] = dep[x]+1;
// 		dfs(v,x);
// 	}
// }

// int lca(int x,int y){
// 	if(dep[x]!=dep[y]){
// 		if(dep[x] < dep[y]) swap(x,y);
// 		for(int i = 20;i>=0;i--){
// 			if(dep[f[x][i]]>=dep[y]) {
// 				x=f[x][i];
// 			}
// 		}
// 	}
// 	if(x==y) return x;
// 	for(int i= 20;i>=0;i--){
// 		int fx= f[x][i];
// 		int fy = f[y][i];
// 		if(fx!=fy) {
// 			x= fx;
// 			y=fy;
// 		}
// 	}
// 	return f[x][0];
// }
// int main()
// {


// 	return 0;
// }



//哈希
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long 
// const int mod = 1e9+7;
// const int B = 233;
// int f[500];

// int qmi(int a,int b,int mod){
// 	int res=1;
// 	while(b){
// 		if(b&1) {
// 			res *= a;
// 			res%=mod;
// 		}
// 		a=a*a%mod;
// 		b>>=1;
// 	}
// 	return res;
// }
// int get_hash(int l,int r){
// 	int now = f[r]-f[l]*qmi(B,r-l+1,mod);
// 	now %=mod;
// 	if(now<0) now+=mod;
// 	return now;
// }
// signed main()
// {	
// 	int n; cin>>n;
// 	string s;
// 	cin>>s;
// 	for(int i=1;i<=n;i++){
// 		f[i]=f[i-1]*B+s[i];
// 		f[i]%=mod;
// 	}

// 	return 0;
// }