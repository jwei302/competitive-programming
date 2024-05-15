#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct FenwickTree{
	vector<ll> ft;
	FenwickTree(int N){
		ft.assign(N+1, 0);
	}
	ll qry(int i){
		ll sum = 0;
		for(; i; i-= (i&-i))
			sum += ft[i];
		return sum;
	}	
	void upd(int i, ll v){
		for(; i < (int)ft.size(); i+=(i&-i))
			ft[i]+=v;
	}
	int select(ll k){
		int lb = 0, rb = ft.size()-1;
		for(int i = 0; i < 30; ++i){
			int mid = (lb+rb)/2;
			qry(mid)<k?lb=mid:rb=mid;
		}
		return rb;
	}

};
struct RUPQ{
	FenwickTree ft;
	RUPQ(int m): ft(FenwickTree(m)) {}
	void range_upd(int i, int j, int v){
		ft.upd(i, v);
		ft.upd(j+1, -v);
	}
	ll pt_qry(int i){
		return ft.qry(i);
	}
};

struct RURQ{
	RUPQ rupq;
	FenwickTree purq;
	RURQ(int m): rupq(RUPQ(m)), purq(FenwickTree(m)) {}
	void range_upd(int i, int j, int v){
		rupq.range_upd(i, j, v);
		purq.upd(i, v*(i-1));
		purq.upd(j+1, -v*j);
	}
	ll qry(int j){
		return rupq.pt_qry(j)*j-purq.qry(j);
	}
};

const int mxN = 2e5;
int N, Q, f[mxN], type, a, b, u, k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	FenwickTree ft(N);
	RUPQ rupq(N);
	for(int i = 0; i < N; ++i)
		cin >> f[i];
	for(int i = 0; i < N; ++i)
		ft.upd(i+1, f[i]);
	while(Q--){
		cin >> type;
		if(type==1){
			cin >> a >> b >> u;
			rupq.range_upd(a, b, u);
		}
		else{
			cin >> k;
			if(k>1)
				cout << ft.qry(k)-ft.qry(k-1)+rupq.pt_qry(k) << '\n';
			else
				cout << ft.qry(k)+rupq.pt_qry(k) << '\n';
		}
	}
	return 0;
}

