#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9+7;

const int mxN = 1e5;
ll N, K, h[mxN], dp[mxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for(int i = 0; i < N; ++i)
		cin >> h[i];
	for(int i = 0; i < N; ++i)
		dp[i] = inf;
	dp[0] = 0;
	for(int i = 1; i < N; ++i){
		for(int j = 1; j <= K; ++j){
			if(i>=j)
				dp[i] = min(dp[i-j]+abs(h[i-j]-h[i]), dp[i]);
		}
	}
	cout << dp[N-1] << '\n';
	return 0;
}

