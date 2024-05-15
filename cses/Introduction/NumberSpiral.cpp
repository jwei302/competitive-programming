#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> y >> x;
		if( x > y ){
			if( x % 2 == 1 ){
				cout << x * x - (y-1) << '\n';
			}else{
				cout << (x-1) * (x-1) + y << '\n';
			}
		}else if ( x < y ){
			if( y % 2 == 0 ){
				cout << y * y - (x-1) << '\n';
			}else{
				cout << (y-1) * (y-1) + x << '\n';
			}
		}else{
			if( x % 2 == 1 ){
				cout << x*x - (y-1) <<'\n';
			}else{
				cout << y*y - (x-1) << '\n';
			}
		}	
	}
	return 0;
}

