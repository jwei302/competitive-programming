#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
vector<ll> adj[mxN], children[mxN], cnt(mxN);
vector<bool> vis(mxN);
ll N, a, b, ans;

void dfs(ll u = 0){
	vis[u] = 1;
	for(ll v: adj[u]){
		if(!vis[v]){
			children[u].push_back(v);
			dfs(v);
		}
	}
}
void dfs1(ll u = 0){
	ans += ceil(log2(children[u].size()+1)) + children[u].size();
	for(ll child: children[u]){
		if(children[child].size()!=0)
			dfs1(child);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(ll i = 0; i < N-1; ++i){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	for(ll i = 0; i < N; ++i){
		for(ll j = 0; j < children[i].size(); ++j)
			if(children[children[i][j]].size()>0)
				cnt[i]++;
	}
	dfs1();
	cout << ans << '\n';
}
