#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int N;
 
void solve(){
	cin >> N;
	vector<int> a;
	cout << 2 << '\n';
	for(int i=1; i<=N; ++i)
		a.push_back(i);
	int p = N;
	while(p>=2){
		p--;
		cout << a[p-1] << " " << a[p] << '\n';
		a[p-1] = (a[p]+a[p-1]+1)/2;
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
