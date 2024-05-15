#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5;
ll N, M;
vector<vector<ll>> a(MAX, vector<ll>(2));

//binary search the answer

bool ok(ll D){
	ll p = a[0][0], cnt = 0;
	for(int i = 0; i < M; ++i){
		if(p < a[i][0]){
			p = a[i][0];
		}
		else if(p > a[i][1]){
			continue;
		}
		ll poss = (a[i][1]-p)/D + 1; 
		cnt += poss;
		p += poss*D;
		
	}
	if(cnt < N) return 0;
	return 1;
}

int main(){
	ifstream cin("socdist.in");
	ofstream cout("socdist.out");
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
		cin >> a[i][0] >> a[i][1];
	}
	sort(a.begin(), a.begin()+M);
	ll lb = 0, rb = 1e18, mid;
	for(int i = 0; i < 100; ++i){
		mid = (lb+rb)/2;
		ok(mid)?lb = mid: rb = mid;
	}
	cout << lb << '\n';
}
