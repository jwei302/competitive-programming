#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9+5
const int mxN = 1e6;
int N, dp[mxN+1];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i <= mxN; ++i){
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int i = 1; i <= N; ++i){
		string num = to_string(i);
		for(int j = 0; j < (int)num.length(); ++j){
			int number = num[j]-'0';
			if(i>=number){
				dp[i] = min(dp[i-number]+1, dp[i]);
			}
		}
	}
	cout << dp[N] << '\n';
	return 0;
}

