#include <bits/stdc++.h>
using namespace std;



struct node{
	int dis;
	bool operator < (node & k )const{
		return dis<k.dis;
	}
};
priority_queue<node>q;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
signed main()
{
	return 0;
}