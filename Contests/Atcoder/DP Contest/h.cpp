#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e3, MOD = 1e9+7;
int H, W, dp[MAX][MAX];
string grid[MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W;
	for(int i = 0; i < H; ++i)
		cin >> grid[i];
	dp[0][0] = 1;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			if(i)
				(dp[i][j] += dp[i-1][j]) %= MOD;
			if(j)
				(dp[i][j] += dp[i][j-1]) %= MOD;
			if(grid[i][j]=='#')
				dp[i][j] = 0;
		}
	}
	cout << dp[H-1][W-1] << '\n';
	return 0;
}

