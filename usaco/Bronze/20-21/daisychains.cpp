//brute force
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e2;
ll N;
vector<ll> a(mxN);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(ll i = 0; i < N; ++i)
		cin >> a[i];
	ll ans = N;
	for(ll i = 0; i < N; ++i){
		ll cursum = a[i];
		for(ll j = i+1; j < N; ++j){
			cursum += a[j];
			if(cursum % (j-i+1) != 0)
				continue;
			ll avg = cursum / (j-i+1);
			for(ll k = i; k <= j; ++k){
				if(a[k]==avg){
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << '\n';
}
