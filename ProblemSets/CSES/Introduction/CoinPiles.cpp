#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
int t, a, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(b>a) swap (a, b);
		if(a > 2*b){
			cout << "NO\n";
			continue;
		}
		a %= 3, b %= 3;
		if((a+b)%3==0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
			
