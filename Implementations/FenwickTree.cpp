#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<vi> vii;
typedef vector<vl> vll;
typedef vector<vd> vdb;
typedef vector<vb> vbb;
typedef vector<vc> vcc;
typedef vector<vs> vss;

#define f first
#define s second	
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define part(x, n) (x).begin(), (x).begin()+n
#define rpart(x, n) (x).rbegin(), (x).rbegin()+n
#define rsz readsize
#define ins insert
#define cnt count
#define fr front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define LSOne(S) ((S)&-(S))

#define F0R(i, a, b) for(int i = (a); i < (b); ++i)
#define FOR(i, a) F0R(i, 0, a)
#define R0F(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define ROF(i, a) R0F (i, 0, a)
#define trav(a, x) for (auto& a: x)

const int MOD = 1e9+7;

//input
template<class A> void read(complex<A>& c);
template<class A, class B> void read(pair<A,B>& p);
template<class A> void read(vector<A>& v);
template<class A, size_t SZ> void read(array<A,SZ>& a);

template<class T> void read(T& x) { cin >> x; }
void read(db& d) { str t; read(t); d = stod(t); }
void read(ld& d) { str t; read(t); d = stold(t); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }

template<class A> void read(complex<A>& c) { A a,b; read(a,b); c = {a,b}; }
template<class A, class B> void read(pair<A,B>& p) { read(p.f,p.s); }
template<class A> void read(vector<A>& x) { trav(a,x) read(a); }
template<class A, size_t SZ> void read(array<A,SZ>& x) { trav(a,x) read(a); }

//output
template<class A> void print(A x) { cout << (x); }
template<class H, class... T> void print(const H& h, const T&... t) {
	print(h); print(t...); }
void prints() { print("\n"); } // print w/ spaces
template<class H, class... T> void prints(const H& h, const T&... t) {
	print(h); if (sizeof...(t)) print(" "); prints(t...); }

void setIn(str s) {freopen(s.c_str(), "r", stdin);}
void setOut(str s) { freopen(s.c_str(), "w", stdout);}
void unsyncIO() { ios::sync_with_stdio(0); cin.tie(0);}
void setIO(str s= ""){
	unsyncIO();
	if(sz(s)) { setIn(s+".in"), setOut(s+".out");}
}

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
int main(){
	setIO();
	return 0;
}

