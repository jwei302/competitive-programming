#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	if( a < b){
		a *= 2;
		int mx = max(pow(a, 2), pow(b, 2));
		cout << mx << endl;
	}else{
		b *= 2;
		int mx = max(pow(a, 2), pow(b, 2));
		cout << mx << endl;
	}
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
