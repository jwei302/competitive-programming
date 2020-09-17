#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
int N, M, u, v;
vector<int> adj[mxN], cur;
vector<vector<int>> cc;
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	cur.push_back(u);
	for(int v: adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	while(M--){
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
	}
	for(int i = 0; i < N; ++i){
		if(!vis[i]){
			cur.clear();
			dfs(i);
			cc.push_back(cur);
		}
	}
	cc.size()==1?cout<<"YES\n":cout<<"NO\n"<<cc[0][0] << " " << cc[1][0] << '\n';
	return 0;
}

