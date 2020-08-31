#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int s1, v1, p1, mx =0;
	while(n--){
		cin >> s1 >> p1 >> v1;
		mx = max(mx, (p1/(s1+1)) * v1);
	}
	cout << mx << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
