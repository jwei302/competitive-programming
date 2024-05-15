#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		ll a = i * i * (i * i - 1) / 2;
		ll b = 2 * (i - 2) * (2 * (i - 4) + 6);
		cout << a-b << '\n';
	}	
	return 0;
}
