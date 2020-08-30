#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	while(k > 0){
		if(b[0] > a[0]){
			a[0] = b[0];
		}else{
			break;
		}
		b.erase(b.begin());
		sort(a.begin(), a.end());
		k--;
	}
	int res = 0;
	for(int i = 0; i < n; ++i){
		res+= a[i];
	}
	cout << res << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
