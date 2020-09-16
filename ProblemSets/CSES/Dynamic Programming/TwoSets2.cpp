#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e2, MOD = 1e9+7;
int N, dp[mxN][mxN*(mxN+1)/2+1];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int sum = N*(N+1)/2;
	if(sum&1){
		cout << 0 << '\n';
		return 0;
	}
	sum/=2;
	dp[0][0] = 1;
	for(int i = 1; i < N; ++i){
		for(int j = 0; j <= sum; ++j){
			dp[i][j] = dp[i-1][j];
			if(j>=i){
				(dp[i][j] += dp[i-1][j-i])%=MOD;
			}
		}
	}
	cout << dp[N-1][sum] << '\n';
	return 0;
}

