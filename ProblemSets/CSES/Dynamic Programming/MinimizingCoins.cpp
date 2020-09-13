#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9+5
const int mxN = 1e2, mxX = 1e6;
int N, X, coins[mxN], dp[mxX+1];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;
	for(int i = 0; i < N; ++i){
		cin >> coins[i];
	}
	for(int i = 1; i <= X; ++i){
		dp[i] = INF;
	}
	for(int i = 1; i <= X; ++i){
		for(int j = 0; j < N; ++j){
			if(i>=coins[j]){
				dp[i] = min(dp[i-coins[j]]+1, dp[i]);
			}
		}
	}
	dp[X]==INF?cout << -1 << '\n':cout << dp[X] << '\n';
	return 0;
}

