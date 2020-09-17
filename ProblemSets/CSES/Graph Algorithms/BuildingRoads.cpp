#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
int N, M, u, v;
vector<int> adj[mxN], cur;
vector<vector<int>> cc;
bool vis[mxN];

//connected components

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
		adj[v].push_back(u);
	}
	for(int i = 0; i < N; ++i){
		if(!vis[i]){
			cur.clear();
			dfs(i);
			cc.push_back(cur);
		}
	}
	cout << cc.size()-1 << '\n';
	for(int i = 1; i < (int)cc.size(); ++i){
		cout << cc[0][0]+1 << " " << cc[i][0]+1 << '\n';
	}
	return 0;
}

