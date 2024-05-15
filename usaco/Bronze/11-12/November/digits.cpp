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

//brute force through all possible combination of digits, convert them to decimal, if equal then decimal number is your answer.
str convert(str s, int base){
	int res = 0, mult = 1;
	ROF(i, sz(s)){
		res += (s[i]-'0')*mult;
		mult *= base;
	}
	return to_string(res);
}
bool cmp(str a, str b){
	a = convert(a, 2);
	b = convert(b, 3);
	return a == b;
}
int main(){
	setIO("digits");
	str n2, n3, t2, t3_1, t3_2;
	cin >> n2 >> n3;
	FOR(i, sz(n2)){
		t2 = n2;
		n2[i] == '0' ? t2[i] = '1': t2[i] = '0';
		FOR(j, sz(n3)){
			t3_1 = n3, t3_2 = n3;
			if(n3[j] == '0'){
				t3_1[j] = '1';
				t3_2[j] = '2';
			}
			else if (n3[j] == '1'){
				t3_1[j] = '0';
				t3_2[j] = '2';
			}
			else{
				t3_1[j] = '0';
				t3_2[j] = '1';
			}
			if(cmp(t2, t3_1)||cmp(t2, t3_2)){
				cout<<convert(t2, 2)<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
