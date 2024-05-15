#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	map<ll, ll> mp;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if( a[i] % k != 0)
			mp[k-a[i] % k] ++;
	}
	bool ok = true;
	for(int i = 0; ok && i < n; ++i)
		if( a[i] % k != 0)
			ok = false;
	if( ok ){
		cout << 0 << '\n';
		return;
	}
	ll ans = 0;
	for(auto a: mp){	
		ans = max((a.second-1)*k +a.first + 1, ans);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

