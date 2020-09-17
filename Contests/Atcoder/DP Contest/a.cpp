#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
ll N, h[mxN], dp[mxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> h[i];
	for(int i = 1; i < N; ++i){
		dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
		if(i>=2)
			dp[i] = min(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout << dp[N-1] << '\n';
	return 0;
}

