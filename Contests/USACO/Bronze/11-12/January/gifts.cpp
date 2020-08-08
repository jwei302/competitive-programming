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

//Brute force solution, try applying the coupon on all of the cows and greedily take as many gifts as possible aftwerwards

bool cmp (pi a, pi b){
	return a.f+a.s < b.f+b.s;
}
int main(){
	//setIO("gifts");
	int n, b;
	cin >> n >> b;
	vpi a(n), copy(n);
	FOR(i, n)
		cin >> a[i].f >> a[i].s;
	int ans = 0, cur, cur_sum;
	FOR(i, n){
		copy = a;
		cur = 0, cur_sum = 0;
		copy[i].f /= 2;
		sort(all(copy), cmp);
		FOR(j, n){
			if(copy[j].f+copy[j].s+cur_sum <= b){
				cur_sum += copy[j].f+copy[j].s;
				cur++;
			}
			else
				break;
		}
		ans = max(cur, ans);
	}
	cout << ans << '\n';
	return 0;
}
