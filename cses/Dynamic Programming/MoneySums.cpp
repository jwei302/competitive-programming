#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e2, mxX = 1e5;
int N, a[mxN], dp[mxN+1][mxX+1];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	set<int> ans;
	int s = 0;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		s += a[i];
	}
	for(int i = 0; i <= N; ++i){
		dp[i][0] = 1;
	}
	for(int j = 1; j <= s; ++j){
		for(int i = 1; i <= N; ++i){
			dp[i][j] = dp[i-1][j];
			if(j>=a[i-1]){
				dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i][j]);
			}
			if(dp[i][j]){
				ans.insert(j);
			}
		}
	}
	cout << ans.size() << '\n';
	for(int num: ans){
		cout << num << " ";
	}
	cout << '\n';
	return 0;
}

