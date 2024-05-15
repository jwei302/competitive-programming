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

#define f first
#define s second	
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(a) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define cnt count
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

//observation1: check each row and the row after, has to be there in at least 4 of them (one time they are being mischeivous)
//it is possible for two things to both have at least 4, thus go from back. O(n) solution
//observation2: the relative position for two cows must be the same for at least 3 out of the 5 photos (messes up each time cow is mischeivous). 
//Keep cow positions and sort based on whether or not there relative positions are correct, if not they are out of order. O(nlogn)

map<int, int> mp[5];
bool cmp(const int a, const int b){
	int cnt = 0;
	FOR(i, 5)
		cnt += mp[i][a]<mp[i][b];
	return cnt >= 3;
}
int main(){
	setIO("photo");
	int n;
	cin >> n;
	vi ans(n);
	FOR(i, 5){
		FOR(j, n){
			int x;
			cin >> x;
			mp[i][x] = j;
			ans[j] = x;
		}
	}
	sort(all(ans), cmp);
	FOR(i, n)
		cout << ans[i] << '\n';
	return 0;
}
