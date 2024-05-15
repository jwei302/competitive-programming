#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int x, y, n;
	cin >> x >> y >> n;
	if( n % x == 0){
		if( y == 0)
			cout<< n << '\n';
		else
			cout << n - x +y << '\n';
	}else{
		if((n/x)*x + y <= n ){
			cout << (n/x)*x + y << '\n';
		}
		else{
			cout << (n/x)*x - x + y << '\n';
		}
	}
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
