#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6;
ll n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll total = n*(n+1)/2;
	if(total&1){
		cout << "NO\n";
		return 0;
	}
	else{
		cout << "YES\n";
		vector<ll> a, b;
		total >>= 1;
		while(n){
			if(total-n>=0){ a.push_back(n); total -= n; }
			else b.push_back(n);
			n--;
		}
		cout << a.size() << '\n';
		for(ll num: a) cout << num << " ";
		cout << '\n' << b.size() << '\n';
		for(ll num: b) cout << num << " ";
		cout << '\n';
	}		
	return 0;
}
