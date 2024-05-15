#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> ans;
	set<int> s;
	for(int i = 0; i < 2*n; ++i){
		int num;
		cin >> num;
		if( !s.count(num)){
			ans.push_back(num);
			s.insert(num);
		}
	}
	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	cout << '\n';	
}
int main(){
	FASTIO;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

