#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
void solve(){
	int n, m;
	cin >> n >> m;
	if( n==1){
		cout << 0 << endl;
	}else if(n==2){
		cout << m << endl;
	}else{
		cout << m*2 << endl;
	}
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
