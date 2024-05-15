#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if( n == 1){
		cout << 0 << '\n';
		return;
	}
	int ind = -1;
	for(int i = n-1; i >= 1; --i){
		if( a[i] > a[i-1]){
			ind = i;
			break;
		}
	}
	if( ind == -1){
		cout << 0 << '\n';
		return;
	}
	int ans = 0;
	for(int i = 0; i < ind; ++i){
		if( a[i] > a[i+1])
			ans = i+1;
	}
	cout << ans << '\n';
}
int main(){
	FASTIO;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

