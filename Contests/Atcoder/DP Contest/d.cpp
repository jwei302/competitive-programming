#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3, mxW = 1e5;
ll N, W, w[mxN], v[mxN], dp[mxN+1][mxW+1];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> W;
	for(int i = 0; i < N; ++i)
		cin >> w[i] >> v[i];
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= W; ++j){
			dp[i][j] = dp[i-1][j];
			if(j>=w[i-1])
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
		}
	}
	cout << dp[N][W] << '\n';
	return 0;
}

