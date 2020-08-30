#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int ans = INT_MAX;
	for(int i = 1; i < n; ++i){
		ans = min(ans, arr[i]-arr[i-1]);
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
