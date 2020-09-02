class FenwickTree{
	private:
		vl ft;
	public:
		FenwickTree(int m){
			ft.assign(m+1, 0);
		}
		ll rsq(int j){
			ll sum = 0;
			for(; j; j-=LSOne(j))
				sum += ft[j];
			return sum;
		}
		ll rsq(int i, int j){
			return rsq(j)-rsq(i-1);
		}
		void update(int i, ll v){
			for(; i < sz(ft); i+=LSOne(i))
				ft[i]+=v;
		}
};
