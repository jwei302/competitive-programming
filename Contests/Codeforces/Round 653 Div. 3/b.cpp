#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	int two = 0, three = 0;
	while ( n % 2 == 0){
		n /= 2;
		two++;
	}
	while( n % 3 == 0){
		n/=3;
		three++;
	}
	if( n == 1 && two <= three){
		cout << 2*three - two << '\n';
	}
	else{
		cout << -1 << '\n';
	}
	return;
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

