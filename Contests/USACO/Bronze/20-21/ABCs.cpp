#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> a(7);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < 7; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll A = a[0];
	ll sum = a[6];
	ll BC = sum-A;
	for(ll i = 1; i < 6; ++i)
		for(ll j = i+1; j < 6; ++j)
			if(a[i]+a[j]==BC)
				cout << A << " " << a[i] << " " << a[j] << '\n';
	return 0;
}
