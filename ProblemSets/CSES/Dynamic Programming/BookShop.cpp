#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3, mxX = 1e5;
ll N, X, h[mxN], s[mxN], dp[mxN+1][mxX+1];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;
	for(int i = 0; i < N; ++i){
		cin >> h[i];
	}
	for(int i = 0; i < N; ++i){
		cin >> s[i];
	}
	for(int i = 1; i <= N; ++i){
		for(int j = 0; j <= X; ++j){
			dp[i][j] = dp[i-1][j];
			if(j>=h[i-1]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]]+s[i-1]);
			}
		}
	}
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= X; ++j){
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
	cout << dp[N][X] << '\n';	
	return 0;
}

