#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod (ll)1e9+7
const int mxN = 1e3;
char c[mxN][mxN];
ll N, dp[mxN][mxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> c[i][j];
		}
	}
	if(c[0][0]=='*'){
		cout << 0 << '\n';
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(i==0&&j==0){
				continue;
			}
			if(c[i][j] =='*'){
				continue;
			}
			if(i-1>=0){
				(dp[i][j] += dp[i-1][j]) %= mod;
			}
			if(j-1>=0){
				(dp[i][j] += dp[i][j-1]) %= mod;
			}
		}
	}
	cout << dp[N-1][N-1] << '\n';
	return 0;
}

