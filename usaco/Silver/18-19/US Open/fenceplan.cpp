#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5;
ll N, M, x[MAX], y[MAX], u, v;
vector<ll> adj[MAX], cur;
vector<vector<ll>> cc;
bool vis[MAX];

void dfs(ll u){
	vis[u] = 1;
	cur.push_back(u);
	for(ll v: adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
int main(){
	ifstream cin("fenceplan.in");
	ofstream cout("fenceplan.out");
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		cin >> x[i] >> y[i];
	}
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
	ll ans = INT_MAX;
	for(int i = 0; i < (int)cc.size(); ++i){
		ll min_y = INT_MAX, min_x = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
		for(int j = 0; j < (int)cc[i].size(); ++j){
			min_x = min(x[cc[i][j]], min_x);
			max_x = max(x[cc[i][j]], max_x);
			min_y = min(y[cc[i][j]], min_y);
			max_y = max(y[cc[i][j]], max_y);
		}
		ans = min(2*(max_x-min_x+max_y-min_y), ans);
	}
	cout << ans << '\n';
	return 0;
}

