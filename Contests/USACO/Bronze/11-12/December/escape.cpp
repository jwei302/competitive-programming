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

//Generate subsets, prune the search to make sure it still works, otherwise break out and move on to next subset. You can also do the recursive way, this is bitset way.

bool check(int a, int b){
	while(a!=0&&b!=0){
		if(a%10+b%10>=10)
			return 0;
		a/=10, b/=10;
	}
	return 1;
}
int main(){
	setIO("escape");
	int n;
	cin >> n;
	vi a(n);
	FOR(i, n)
		cin >> a[i];
	int ans = 0, cur, cur_sz = 0;
	bool ok;
	FOR(i, 1<<n){
		cur = 0, cur_sz = 0, ok = 1;
		FOR(j, n)
			if(i & (1 << j)){
				if(check(cur, a[j]))
					cur += a[j];
				else{
					ok = 0;
					break;
				}
				cur_sz++;
			}
		if(ok)
			ans = max(cur_sz, ans);
	}
	cout << ans << '\n';
	return 0;
}
