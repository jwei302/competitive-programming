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
		ll rsq(int j){
			ll sum=0;
			for(; j; j-=LSOne(j))
				sum+=ft[j];
			return sum;
		}
		ll rsq(int i, int j){
			return rsq(j)-rsq(i-1);
		}
		void update(int i, ll v){
			for(; i<sz(ft); i+=LSOne(i))
				ft[i]+=v;
		}
		int select(ll k){
			int lb=0, rb=sz(ft)-1;
			FOR(i, 30){
				int mid = (lb+rb)/2;
				(rsq(1, mid)<k)?lb=mid:rb=mid;
			}
			return rb;
		}
};

class RUPQ{
	private: 
		FenwickTree ft;
	public:
		RUPQ(int m): ft(FenwickTree(m)) {}
		void range_update(int i, int j, int v){
			ft.update(i, v);
			ft.update(j+1, -v);
		}
		ll point_query(int i){
			return ft.rsq(i);
		}
};

class RURQ{
	private:
		RUPQ rupq;
		FenwickTree purq;
	public:
		RURQ(int m): rupq(RUPQ(m)), purq(FenwickTree(m)) {}
		void range_update(int i, int j, int v){
			rupq.range_update(i, j, v);
			purq.update(i, v*(i-1));
			purq.update(j+1, -v*j);
		}
		ll rsq(int j){
			return rupq.point_query(j)*j-purq.rsq(j);
		}
		ll rsq(int i, int j){
			return rsq(j)-rsq(i-1);
		}
};
