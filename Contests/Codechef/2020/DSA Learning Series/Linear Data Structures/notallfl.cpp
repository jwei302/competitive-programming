#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(k+1);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = 0, cur = 0, j = 0;
	for(int i = 0; i < n; ++i){
		if(b[a[i]] == 0){
			cur++;
		}
		b[a[i]]++;
		if( cur < k ){
			ans = max(ans, i-j+1);
		}
		while( cur == k ){
			b[a[j]]--;
			if(b[a[j]] == 0){
				cur--;
			}
			j++;
		}
	}	
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
