#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mxN = 1e6;
ll N, mx[mxN];

void solve(){
	cin >> N;
	ll ans = 0, min = INT_MAX;
	for(int i = 0; i < N; ++i){
		cin >> mx[i];
		if(mx[i] < min){
			min = mx[i];
		}
		ans += min;
	}
	cout << ans << endl;
}
int main(){

	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

