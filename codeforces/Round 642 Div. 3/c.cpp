#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
void solve(){
	int n;
	cin >> n;
	ll res = 0;
	int mult = 1;
	for(int i = 3; i <= n; i+=2){
		res += (pow(i,2)-pow((i-2),2))*mult;
		mult++;
	}
	cout << res << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
