/*
ID: jeffrey88
PROG: subset
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 39;
ll N, dp[mxN+1][mxN*(mxN+1)/4+10];

int main(){
	ifstream cin("subset.in");
	ofstream cout("subset.out");
	cin >> N;
	ll sum = N*(N+1)/2;
	if(sum&1){
		cout << 0 << '\n';
		return 0;
	}
	sum >>= 1;
	for(int j = 1; j <= sum; ++j){
		dp[0][j] = 0;
	}
	for(int i = 0; i <= N; ++i){
		dp[i][0] = 1;
	}
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= sum; ++j){
			//if we don't use this number
			dp[i][j] += dp[i-1][j];
			//if we do use this number
			if(i<=j){
				dp[i][j] += dp[i-1][j-i];
			}
		}
	}
	cout << dp[N][sum]/2 << '\n';
	return 0;
}

