#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mxN = 2e5 + 1;
int ar[mxN];

void solve(){
	int a; cin >> a;
	priority_queue<pair<int, pair<int, int>>>mx;
	mx.push(mp(a, mp(-1, -a)));
	int cnt = 1;
	while(!mx.empty()){
		int l = -mx.top().second.first;
		int r = -mx.top().second.second;
		mx.pop();

		int mid = (l+r)/2;
		ar[mid] = cnt;
		cnt++;
		if(l == r){
			continue;
		}
		if(l < mid){
			mx.push(mp(mid - l, mp(-l, -(mid-1))));
		}
		if(mid < r){
			mx.push(mp(r - mid, mp(-(mid+1), -r)));
		}
	}
	for(int i = 1; i <= a; ++i){
		cout << ar[i] << " ";
	}
	cout << endl;
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
