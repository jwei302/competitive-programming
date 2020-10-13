
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 2e5;
ll N, K, a[mxN];
 
void solve(){
	cin >> N >> K;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a+N);
	ll ans = 0;
	for(int i = N-1; i >= N-K-1; --i)
		ans+=a[i];
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
