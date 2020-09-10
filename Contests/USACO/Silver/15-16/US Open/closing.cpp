#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 3e3;
int n, m, u, v, close;
vector<int> adj[MAX];
bool vis[MAX], closed[MAX];

void dfs(int u){
	vis[u] = 1;
	for(int v: adj[u]){
		if(closed[v]||vis[v]) continue;
		dfs(v);
	}
}

int main(){
	ifstream cin("closing.in");
	ofstream cout("closing.out");
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; ++i){
		memset(vis, 0, sizeof(vis));
		for(int j = 0; j < n; ++j){
			if(!closed[j]){
				dfs(j);
				break;
			}
		}
		bool ok = 1;
		for(int j = 0; j < n; ++j){
			if(!closed[j]&&!vis[j]){
				ok = 0;
				break;
			}
		}
		if(ok){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
		cin >> close;
		closed[close-1] = 1;
	}
	return 0;
}

