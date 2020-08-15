#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	vector<ll>a(n-1);
	for(int i = 0; i < n-1; ++i)
		cin >> a[i];
	int total = (n*(n+1))/2;
	for(int i = 0; i < n-1; ++i)
		total -= a[i];
	cout << total << '\n';
	return 0;
}

