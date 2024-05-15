#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll)1e9+7

const int mxN = 1e6;
ll dp[mxN+1], N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	dp[0] = 1;
	for(int i = 1; i <= N; ++i){
		for(int j = i-1; j >= max(i-6, 0); --j){
			(dp[i] += dp[j]) %= MOD;
		}
	}
	cout << dp[N] << '\n';
	return 0;
}

