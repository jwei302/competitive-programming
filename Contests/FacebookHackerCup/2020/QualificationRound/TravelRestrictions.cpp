#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

#define pb push_back
#define all(a) (a).begin(), (a).end()
#define size(a) (int)(a).size()
#define FOR(a) for(int i = 0; i < (a); ++i)
#define read(a) FOR(size(a)) cin >> (a)[i]
#define output(a) FOR(size(a)) cout << (a)[i] << " ";

const int mxN = 50;
vector<bool>a(mxN), b(mxN);
vector<vector<bool>>ans(mxN,vector<bool>(mxN));
void solve(){
	int n;
	cin >> n;
	FOR(n){
		char c;
		cin >> c;
		c=='Y'?a[i]=1:a[i]=0;
	}
	FOR(n){
		char c;
		cin >> c;
		c=='Y'?b[i]=1:b[i]=0;
	}
	for(int i = 0; i < n; ++i){
		ans[i][i] = 1;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i==j)
				continue;
			bool ok = true;
			if(i>j){
				if(!b[i])
					ok = false;
				for(int cur = i-1; ok&&cur > j; --cur)
					if(!a[cur]||!b[cur])
						ok = false;
				if(!a[j])
					ok = false;
			}
			else{
				if(!b[i])
					ok = false;
				for(int cur = i+1; ok&&cur < j; ++cur)
					if(!a[cur]||!b[cur])
						ok = false;
				if(!a[j])
					ok = false;
			}
			ok?ans[i][j]=1:ans[i][j]=0;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(ans[i][j])
				cout << 'Y';
			else
				cout << 'N';
		}
		cout<<'\n';
	}
}
int main(){
	freopen("travel_restrictions_input.txt", "r", stdin);
	freopen("travel_restrictions_output.txt", "w", stdout);
	int t;
	cin >> t;
	FOR(t){
		cout << "Case #" << i+1 << ":\n";
		solve();
	}
	return 0;
}
