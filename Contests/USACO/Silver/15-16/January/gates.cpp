#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3;
string s;
int N, x = 1002, y = 1002, CC, minx = 2*mxN+5, miny = 2*mxN+5, maxx, maxy;
bool vis[2*mxN+5][2*mxN+5], a[2*mxN+5][2*mxN+5];

//floodfill to find total amount of connected components

void dfs(int i, int j){
	if(i<minx||i>maxx||j<miny||j>maxy||vis[i][j]||a[i][j]){
		return;
	}
	vis[i][j] = 1;
	dfs(i, j+1);
	dfs(i, j-1);
	dfs(i+1, j);
	dfs(i-1, j);
}
int main(){
	ifstream cin("gates.in");
	ofstream cout("gates.out");
	cin >> N >> s;
	a[x][y] = 1;
	for(int i = 0; i < N; ++i){
		int dx = 0, dy = 0;
		if(s[i]=='N') dy = 1;
		else if(s[i]=='S') dy = -1;
		else if(s[i]=='E') dx = 1;
		else dx = -1;
		for(int j = 0; j < 2; ++j){
			x += dx;
			y += dy;
			a[x][y] = 1;
		}
		minx = min(x, minx);
		miny = min(y, miny);
		maxx = max(x, maxx);
		maxy = max(y, maxy);
	}
	minx--, miny--, maxx++, maxy++;
	for(int i = minx; i <= maxx; ++i){
		for(int j = miny; j <= maxy; ++j){
			if(!a[i][j]&&!vis[i][j]){
				dfs(i, j);
				CC++;
			}
		}
	}
	cout << CC-1 << '\n';
	return 0;
}

