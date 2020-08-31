#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int N;
	cin >> N;
	vector<ll> mon(N);
	for(int i = 0; i < N; ++i){
		cin >> mon[i];
	}
	sort(mon.begin(), mon.end());
	ll maxi = 0;
	for(int i = 0; i < N; ++i){
		maxi = max(maxi, mon[i] * (N-i));
	}
	cout << maxi << endl;
}
