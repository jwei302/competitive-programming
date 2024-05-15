#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i <= n/3; ++i){
		for(int j = 0; j <= (n-3*i)/5; ++j){
			if((n-3*i-5*j)%7==0){
				cout << i << " " << j << " " << (n-3*i-5*j)/7 << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
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
