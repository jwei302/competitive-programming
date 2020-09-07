/*
ID: jeffrey88
PROG: castle
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;
typedef pair<str, str> ps;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<ps> vps;
typedef vector<vi> vii;
typedef vector<vl> vll;
typedef vector<vd> vdb;
typedef vector<vb> vbb;
typedef vector<vc> vcc;
typedef vector<vs> vss;
typedef vector<vpi> vvpi;

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

const int mxN = 50;
bool vis[mxN][mxN];
int c[mxN][mxN], cc[mxN][mxN], w[4] = {1, 2, 4, 8}, s, m, n, ct;
vi walls[16], cc_size;

void dfs(int i, int j){
	if(i<0||i>=n||j<0||j>=m||vis[i][j])
		return;
	vis[i][j] = 1;
	cc[i][j] = ct;
	vi poss = walls[c[i][j]];
	if(poss[0]) dfs(i, j-1);
	if(poss[1]) dfs(i-1, j); 
	if(poss[2]) dfs(i, j+1); 
	if(poss[3]) dfs(i+1, j);
	return;
}

int main(){
	setIO("castle");
	read(m, n);
	FOR(i, (1<<4)){
		s = 0;
		vi cur(4, 1);
		FOR(j, 4){
			if(i&(1<<j)){
				s += w[j];
				if(w[j]==1) cur[0] = 0;
				if(w[j]==2) cur[1] = 0;
				if(w[j]==4) cur[2] = 0;
				if(w[j]==8) cur[3] = 0;

			}
		}
		walls[s] = cur;
	}
	FOR(i, n) FOR(j, m) read(c[i][j]);
	memset(cc, -1, sizeof(cc));
	FOR(i, n){
		FOR(j, m){
			if(!vis[i][j]){
				dfs(i, j);
				ct++;
			}
		}
	}
	prints(ct);
	cc_size = vi(ct);
	int mx = 0;
	FOR(i, n) FOR(j, m) cc_size[cc[i][j]]++;
	FOR(i, ct) mx = max(cc_size[i], mx);
	prints(mx);
	mx = 0;
	char dir;
	int ind_i, ind_j;
	FOR(j, m){
		ROF(i, n){
			F0R(k, 1, 3){
				if(k==1&&i==0||k==2&&j==m-1) continue;
				if(k==1&&!walls[c[i][j]][k]){
					if(cc[i][j]!=cc[i-1][j]){
						if(cc_size[cc[i][j]]+cc_size[cc[i-1][j]]>mx){
							mx = cc_size[cc[i][j]]+cc_size[cc[i-1][j]];
							ind_i = i, ind_j = j;
							dir = 'N';
						}
					}
				}
				if(k==2&&!walls[c[i][j]][k]){
					if(cc[i][j]!=cc[i][j+1]){
						if(cc_size[cc[i][j]]+cc_size[cc[i][j+1]]>mx){
							mx = cc_size[cc[i][j]]+cc_size[cc[i][j+1]];
							ind_i = i, ind_j = j;
							dir = 'E';
						}
					}
				}
			}
		}
	}
	prints(mx);
	prints(ind_i+1, ind_j+1, dir);
	return 0;
}

