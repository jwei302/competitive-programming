#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll ans = 1;
	stack<ll> s;
	for(int i = n-1; i >= 0; --i){
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			ans = (ans*(s.top()-i+1))%((ll)(1e9+7));
		s.push(i);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
