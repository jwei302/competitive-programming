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
