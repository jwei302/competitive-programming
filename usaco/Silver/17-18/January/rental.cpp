#include <bits/stdc++.h>
using namespace std;

#define ll long long

//use binary search and prefix sums

const int MAX = 1e5;
ll N, M, R, c[MAX], r[MAX], q[MAX], p[MAX], price[MAX];
pair<ll, ll> qp[MAX];

bool cmp1(ll a, ll b){
	return a>b;
}
bool cmp2(pair<ll, ll> a, pair<ll, ll> b){
	return a.second>b.second;
}
int main(){
	ifstream cin ("rental.in");
	ofstream cout ("rental.out");
	cin >> N >> M >> R;
	for(int i = 0; i < N; ++i){
		cin >> c[i];
	}
	for(int i = 0; i < M; ++i){
		cin >> qp[i].first >> qp[i].second;
	}
	for(int i = 0; i < R; ++i){
		cin >> r[i];
	}
	sort(c, c+N, cmp1);
	sort(qp, qp+M, cmp2);
	sort(r, r+R, cmp1);
	for(int i = 0; i < M; ++i){
		q[i] = qp[i].first;
		p[i] = qp[i].second;
	}
	price[0] = q[0]*p[0];
	for(int i = 1; i < M; ++i){
		price[i] += price[i-1] + q[i]*p[i];
		q[i] += q[i-1];
	}
	for(int i = 1; i < R; ++i){
		r[i] += r[i-1];
	}
	for(int i = 1; i < N; ++i){
		c[i] += c[i-1];
	}
	ll best = 0;
	for(int i = 0; i < N; ++i){
		ll pos = lower_bound(q, q+M, c[i])-q;
		best = max(r[min(R-1, N-1-i-1)] + price[pos-1] + (c[i]-q[pos-1])*p[pos], best);
	}
	cout << best << '\n';
}
	
	
