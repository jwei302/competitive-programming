struct FenwickTree{
	vector<ll> ft;
	FenwickTree(int N){
		ft.assign(N+1, 0);
	}
	ll qry(int i){
		ll sum = 0;
		for(; i; i-= i&-i)
			sum += ft[i];
		return sum;
	}	
	void upd(int i, ll v){
		for(; i < N; i+=i&-i)
			ft[i]+=v;
	}
}
