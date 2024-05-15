#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

void solve(){
	int x, y, z;
	cin >> x >> y >> z;
	if(( x == y && y == z && x == z) || ( (x == y && x > z)|| (x == z && x > y) || (y == z && y > x))){
		cout << "YES\n";
		if( x == y && x  == z && y == z){
			cout << x << " "<< y << " " << z << '\n';
		}
		else if ( x == y && x > z){
			cout << x << " " << z << " " << z << '\n';
		}
		else if ( x == z && x > y)
			cout << x << " " << y << " " << y << '\n';
		else if ( y == z && y > x)
			cout << y << " " << x << " " << x << '\n';
	}
	else{
		cout << "NO\n";
	}
	return;
}

int main(){
	FASTIO;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

