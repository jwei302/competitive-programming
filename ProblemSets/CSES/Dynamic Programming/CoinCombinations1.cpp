#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll)1e9+7

const int mxN = 1e2, mxX = 1e6;
ll N, X, coins[mxN], dp[mxX+1];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;
	for(int i = 0; i < N; ++i){
		cin >> coins[i];
	}
	dp[0] = 1;
	for(int i = 1; i <= X; ++i){
		for(int j = 0; j < N; ++j){
			if(i>=coins[j]){
				(dp[i] += dp[i-coins[j]]) %= MOD;
			}
		}
	}
	cout << dp[X] << '\n';
	return 0;
}

