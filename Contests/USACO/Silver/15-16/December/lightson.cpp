#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};

const ll mxN = 1e2, mxM = 2e4;
ll N, M, x, y, a, b, lights[mxN+1][mxN+1];
vector<array<ll, 2>> switches[mxN+1][mxN+1];
bool vis[mxN+1][mxN+1];

bool ok(ll i, ll j){
	if(i<1||i>N||j<1||j>N)
		return 0;
	return 1;
}
void dfs(ll i, ll j){
	if(!ok(i, j)||!lights[i][j]||vis[i][j])
		return;
	vis[i][j] = 1;
	for(array<ll, 2> ar: switches[i][j]){
		lights[ar[0]][ar[1]] = 1;
		for(ll k = 0; k < 4; ++k){
			ll curx = ar[0]+dx[k], cury = ar[1]+dy[k];
			if(!vis[ar[0]][ar[1]]&&ok(curx, cury)&&vis[curx][cury])
				dfs(ar[0], ar[1]);
		}
	}
	for(ll k = 0; k < 4; ++k)
		dfs(i+dx[k], j+dy[k]);
}
int main(){
	ifstream cin("lightson.in");
	ofstream cout("lightson.out");
	cin >> N >> M;
	while(M--){
		cin >> x >> y >> a >> b;
		switches[x][y].push_back({a, b});
	}
	lights[1][1] = 1;
	dfs(1, 1);
	ll ans = 0;
	for(ll i = 1; i <= N; ++i)
		for(ll j = 1; j <= N; ++j)
			if(lights[i][j])
				ans++;
	cout << ans << '\n';
    return 0;
}

