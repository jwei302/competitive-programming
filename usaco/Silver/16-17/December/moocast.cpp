#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e2;
ll N, reach[mxN], x[mxN], y[mxN], p[mxN];
vector<ll> adj[mxN];
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	for(int v: adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}

int main(){
	ifstream cin("moocast.in");
	ofstream cout("moocast.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> x[i] >> y[i] >> p[i];
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(i==j) continue;
			if((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])<=p[i]*p[i]){
				adj[i].push_back(j);
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < N; ++i){
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for(int j = 0; j < N; ++j){
			if(vis[j]){
				reach[i]++;
			}
		}
		ans = max(reach[i], ans);
	}
	cout << ans << '\n';	
	return 0;
}

