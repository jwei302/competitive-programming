#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e3;
int N, Q, p, q, r, k, v, relevance[mxN][mxN];
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u, int mn, int parent){
	if(u!=parent){
		relevance[parent][u] = mn;
	}
	vis[u] = 1;
	for(int v: adj[u]){
		if(!vis[v]){
			dfs(v, min(mn, relevance[u][v]), parent);
		}
	}
}

int main(){
	ifstream cin("mootube.in");
	ofstream cout("mootube.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for(int i = 0; i < N-1; ++i){
		cin >> p >> q >> r;
		p--, q--;
		relevance[p][q] = r;
		relevance[q][p] = r;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	while(Q--){
		cin >> k >> v;
		v--;
		int cnt = 0; 
		dfs(v, INT_MAX, v);
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < N; ++i){
			if(i==v) continue;
			if(relevance[v][i]>=k) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}

