#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e2;
int N, M, x, y, a, b;
vector<array<int, 2>> adj[mxN][mxN];
bool vis[mxN][mxN], isOn[mxN][mxN];

bool ok(int i, int j){
	if(i-1>=0){
		if(isOn[i-1][j]&&vis[i-1][j]){
			return 1;
		}
	}
	if(i+1<N){
		if(isOn[i+1][j]&&vis[i+1][j]){
			return 1;
		}
	}
	if(j-1>=0){
		if(isOn[i][j-1]&&vis[i][j-1]){
			return 1;
		}
	}
	if(j+1<N){
		if(isOn[i][j+1]&&vis[i][j+1]){
			return 1;
		}
	}
	return 0;
}
void dfs(int i, int j){
	if(vis[i][j]){
		return;
	}
	vis[i][j] = 1;
	for(array<int, 2> v:adj[i][j]){
		isOn[v[0]][v[1]] = 1;
		if(ok(v[0], v[1])&&!vis[v[0]][v[1]]){
			dfs(v[0], v[1]);
		}
	}
	if(i+1<N&&isOn[i+1][j]){
		dfs(i+1, j);
	}
	if(i-1>=0&&isOn[i-1][j]){
		dfs(i-1, j);
	}
	if(j+1<N&&isOn[i][j+1]){
		dfs(i, j+1);
	}
	if(j-1>=0&&isOn[i][j-1]){
		dfs(i, j-1);
	}
}

int main(){
	ifstream cin("lightson.in");
	ofstream cout("lightson.out");
	cin >> N >> M;
	while(M--){
		cin >> x >> y >> a >> b;
		x--, y--, a--, b--;
		adj[x][y].push_back({a, b});
	}
	isOn[0][0] = 1;
	dfs(0, 0);	 
	int ans = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(isOn[i][j]){
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

