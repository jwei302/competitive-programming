class FenwickTree{
	private:
		vl ft;
	public:
		FenwickTree(int m){
			ft.assign(m+1, 0);
		}
		void build(const vl &f){
			ft.assign(sz(f), 0);
			F0R(i, 1, sz(f)){
				ft[i]+=f[i];
				if(i+LSOne(i)<sz(f))
					ft[i+LSOne(i)]+=ft[i];
			}
		}
		FenwickTree(const vl &f){
			build(f);
		}
		ll qry(int j){
			ll sum=0;
			for(; j; j-=LSOne(j))
				sum+=ft[j];
			return sum;
		}
		ll qry(int i, int j){
			return qry(j)-qry(i-1);
		}
		void upd(int i, ll v){
			for(; i<sz(ft); i+=LSOne(i))
				ft[i]+=v;
		}
		int select(ll k){
			int lb=0, rb=sz(ft)-1;
			FOR(i, 30){
				int mid = (lb+rb)/2;
				(qry(1, mid)<k)?lb=mid:rb=mid;
			}
			return rb;
		}
};

class RUPQ{
	private: 
		FenwickTree ft;
	public:
		RUPQ(int m): ft(FenwickTree(m)) {}
		void rng_upd(int i, int j, int v){
			ft.upd(i, v);
			ft.upd(j+1, -v);
		}
		ll pt_qry(int i){
			return ft.qry(i);
		}
};

class RURQ{
	private:
		RUPQ rupq;
		FenwickTree purq;
	public:
		RURQ(int m): rupq(RUPQ(m)), purq(FenwickTree(m)) {}
		void rng_upd(int i, int j, int v){
			rupq.rng_upd(i, j, v);
			purq.upd(i, v*(i-1));
			purq.upd(j+1, -v*j);
		}
		ll qry(int j){
			return rupq.pt_qry(j)*j-purq.qry(j);
		}
		ll qry(int i, int j){
			return qry(j)-qry(i-1);
		}
};
