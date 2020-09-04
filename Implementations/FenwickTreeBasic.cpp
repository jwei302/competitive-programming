vl ft(mxN+1);

ll qry(int j){
	ll sum = 0;
	for(; j; j-=LSOne(j))
		sum += ft[j];
	return sum;
}
void upd(int i, ll v){
	for(; i <= n; i+=LSOne(i))
		ft[i]+=v;
}
