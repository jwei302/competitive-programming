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
typedef vector<pd> vpd;
typedef vector<vi> vii;
typedef vector<vl> vll;
typedef vector<vd> vdb;
typedef vector<vb> vbb;
typedef vector<vc> vcc;
typedef vector<vs> vss;

#define mp make_pair
#define f first
#define s second	
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(a) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define F0R(i, a, b) for(int i = (a); i < (b); ++i)
#define FOR(i, a) F0R(i, 0, a)
#define R0F(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define ROF(i, a) R0F (i, 0, a)
#define trav(a, x) for (auto& a: x)

const int MOD = 1e9+7;

void setIn(str s) {freopen(s.c_str(), "r", stdin);}
void setOut(str s) { freopen(s.c_str(), "w", stdout);}
void unsyncIO() { ios::sync_with_stdio(0); cin.tie(0);}
void setIO(str s= ""){
	unsyncIO();
	if(sz(s)) { setIn(s+".in"), setOut(s+".out");}
}

const int mxN = 50;
vbb vis(mxN, vb(mxN));
vcc a(mxN, vc(mxN));
int n, m;

//floodfill search for all the coordinates from spot1 and spot2, find the minimum manhatten distance between all the points. Input is small so won't TLE

void dfs(int i, int j, vpi &sp){
	if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] != 'X' || vis[i][j])
		return;
	vis[i][j] = true;
	sp.pb({i, j});
	dfs(i+1, j, sp);
	dfs(i-1, j, sp);
	dfs(i, j+1, sp);
	dfs(i, j-1, sp);
}
int main(){
	setIO("pageant");
	vpi sp1, sp2;
	cin >> n >> m;
	FOR(i, n) FOR(j, m) cin>> a[i][j];
	bool first = true, second = true;
	FOR(i, n){
		FOR(j, m){
			if(a[i][j] == 'X'&&!vis[i][j] && first){
				dfs(i, j, sp1);
				first = false;
			}
			if (a[i][j] == 'X' && !vis[i][j] && !first && second){
				dfs(i, j, sp2);
				second = false;
			}
		}
	}
	int min = INT_MAX;
	trav(a, sp1){
		trav(b, sp2){
			if(abs(a.f-b.f)+abs(a.s-b.s)<min)
				min = abs(a.f-b.f)+abs(a.s-b.s);
		}
	}
	cout << min-1 << '\n';
	return 0;
}
