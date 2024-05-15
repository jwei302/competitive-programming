#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
	int n, k;
	cin >> n >> k;
	int mn = n;
	if(k == 1){
		cout << mn << endl;
	}else if(k >= n){
		cout << 1 << endl;
	}else{
		for(int i = 2; i*i <= n ; ++i){
			if( n % i ==0 ){
				if( n/i <= k ){
					mn = min(mn, i);
				}if(i <= k){
					mn = min(mn, n/i);
				}
			}
		}
		cout << mn << endl;
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
