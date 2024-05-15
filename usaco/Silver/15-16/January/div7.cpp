#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e4;
ll N, a[mxN], first[7], last[7];

//find largest subset divisible by 7
//every subset is a larger prefix substracted by a shorter prefix

int main(){
	ifstream cin("div7.in");
	ofstream cout("div7.out");
	cin >> N;
	memset(first, -1, sizeof(first));
	memset(last, -1, sizeof(last));
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		a[i] %= 7;
	}
	for(int i = 1; i < N; ++i){
		(a[i] += a[i-1]) %= 7;
	}
	for(int i = 0; i < N; ++i){
		if(first[a[i]]<0) first[a[i]] = i;
		last[a[i]] = i;
	}
	ll ans = 0;
	for(int i = 0; i < 7; ++i){
		ans = max(last[i]-first[i], ans);
	}
	cout << ans << '\n';
	return 0;
}

