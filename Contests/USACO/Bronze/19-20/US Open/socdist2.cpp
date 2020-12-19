#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N, x, s;
vector<vector<ll>> a(1000, vector<ll>(2));

bool cmp(vector<ll> a, vector<ll> b){
	return a[0]<b[0];
}

int main(){
	ifstream cin("socdist2.in");
	ofstream cout("socdist2.out");
	cin >> N;
	for(ll i = 0; i < N; ++i)
		cin >> a[i][0] >> a[i][1];
	sort(a.begin(), a.begin()+N, cmp);
	ll R = INT_MAX, otherR = INT_MAX;
	for(ll i = 1; i < N; ++i){
		if(a[i][1]^a[i-1][1])
			R = min(a[i][0]-a[i-1][0], R);
		otherR = min(a[i][0]-a[i-1][0], otherR);
	}
	if(R==INT_MAX)
		R = otherR-1;
	R--;
	vector<ll> reg;
	ll ans = 1;
	for(int i = 0; i < N; ++i)
		if(a[i][1])
			reg.push_back(a[i][0]);
	for(int i = 1; i < reg.size(); ++i)
		if(reg[i]>reg[i-1]+R)
			ans++;
	cout << ans << '\n';
}
