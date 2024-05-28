#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
const int mod = 1e9+7;

int qmi(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res * a % mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}
int fa[105];
int inv[105];
void init(){
	fa[1] = 1;
	for(int i=1;i<=100;i++){
		fa[i] = fa[i-1]*i%mod;
	}
	inv[100] = qmi(fa[100],mod-2);
	for(int i=100-1;i>=1;i--){
		inv[i] = inv[i+1] * (i+1) % mod;
	}
}
int C(int x,int y){
	if(x<y) return 0;
	return fa[x]*inv[y]%mod*inv[x-y]%mod;
}

void get_prime_factor(){
	int n = 105;
	vector<int>st(n+5);
	for(int i=2;i<n;i++){
		if(st[i] == 2)continue;
		st[i] = 1;
		for(int j = 2*i;j<n;j+=i){
			st[j] = 2;
		}
	}
	
	vector<int>p;
	int X = 5e5;
	//存储5e5这一个数字的质因数。
	for(int i = 2;i*i<=X;i++){
		if(X%i == 0) {
			p.push_back(i);
			while(X%i == 0) X/=i;
		}
	} 
	if(X>1) p.push_back(X);
}

signed main()
{
	
	return 0;
}
