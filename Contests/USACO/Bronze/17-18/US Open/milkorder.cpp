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
#define rsz resize
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

//Place all the cows that have a specific place in first. Next, brute force check each spot starting from the beginning see if cow 1 can fit, and see if the specific ordering works

int main(){
	setIO("milkorder");
	int n, m, k;
	read(n, m, k);
	vi order(m);
	read(order);
	vi ordering(n, -1);
	int cow, x;
	FOR(i, k){
		read(cow, x);
		x--;
		ordering[x] = cow;
	}
	vi test_ordering;
	FOR(i, n){
		if(ordering[i]!=-1)
			continue;
		else{
			test_ordering = ordering;
			test_ordering[i] = 1;
			bool ok = 1;
			int pos = 0;
			FOR(i, m){
				bool in = 0;
				FOR(j, n){
					if(test_ordering[j]==order[i]){
						pos = j+1;
						in = 1;
					}
				}
				if(in)
					continue;
				while(test_ordering[pos]!=-1&&pos<n)
					pos++;
				if(pos==n){
					ok = 0;
					break;
				}
				test_ordering[pos] = order[i];
			}
			vector<int> positions;
			FOR(i, m){
				FOR(j, n){
					if(test_ordering[j]==order[i]){
						positions.pb(j);
						break;
					}
				}
			}
			if(sz(positions)!=m)
				ok = 0;
			else{
				F0R(i, 1, m){
					if(positions[i]<positions[i-1])
						ok = 0;
				}
			}
			if(ok){
				prints(i+1);
				return 0;
			}
		}
	}
	return 0;
}

