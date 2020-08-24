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

class SegmentTree{
	private:
		int n;
		vi A, st, lazy;
		int l(int p){
			return p<<1;
		}
		int r(int p){
			return (p<<1)+1;
		}
		int conquer(int a, int b){
			if(a==-1)
				return b;
			if(b==-1)
				return a;
			return min(a, b); //change to max for RangeMaxQuery
		}
		void build(int p, int L, int R){
			if(L==R)
				st[p]=A[L];
			else{
				int m =(L+R)/2;
				build(l(p), L, m);
				build(r(p), m+1, R);
				st[p]=conquer(st[l(p)], st[r(p)]);
			}
		}
		void propagate(int p, int L, int R){
			if(lazy[p]!=-1){
				st[p]=lazy[p];
				if(L!=R)
					lazy[l(p)]=lazy[r(p)]=lazy[p];				
				else
					A[L]=lazy[p];
				lazy[p]=-1;
			}
		}
		int RMQ(int p, int L, int R, int i, int j){
			propagate(p, L, R);
			if(i>j)
				return -1;
			if(L>=i&&R<=j)
				return st[p];
			int m = (L+R)/2;
			return conquer(RMQ(l(p), L, m, i, min(m, j)), RMQ(r(p), m+1, R, max(i, m+1), j));
		}
		void update(int p, int L, int R, int i, int j, int val){
			propagate(p, L, R);
			if(i>j)
				return;
			if(L>=i&&R<=j){
				lazy[p]=val;
				propagate(p, L, R);
			}
			else{
				int m = (L+R)/2;
				update(l(p), L, m, i, min(m, j), val);
				update(r(p), m+1, R, max(i, m+1), j, val);
				int lsubtree=lazy[l(p)]!=-1?lazy[l(p)]:st[l(p)];
				int rsubtree=lazy[r(p)]!=-1?lazy[r(p)]:st[r(p)];
				st[p]=(lsubtree<=rsubtree)?st[l(p)]:st[r(p)];
			}
		}
	public:
		SegmentTree(int sz):n(sz), st(4*n), lazy(4*n, -1){};
		SegmentTree(const vi&initialA): SegmentTree(sz(initialA)){
			A=initialA;
			build(1, 0, n-1);
		}
		void update(int i, int j, int val){
			update(1, 0, n-1, i, j, val);
		}
		int RMQ(int i, int j){
			return RMQ(1, 0, n-1, i, j);
		}
};

int main(){
	setIO();
	return 0;
}

