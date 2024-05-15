#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
int N, x, y;
pair<int, int> a[mxN];

//two pointers, greedy

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	ifstream cin("pairup.in");
	ofstream cout("pairup.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+N, cmp);
	int ans = 0, lb = 0, rb = N-1;
	while(lb<=rb){
		ans = max(a[lb].second+a[rb].second, ans);
		int mn = min(a[lb].first, a[rb].first); 
		a[lb].first -= mn;
		a[rb].first -= mn;
		if(a[lb].first<=0){
			lb++;
		}
		if(a[rb].first<=0){
			rb--;
		}
	}
	cout << ans << '\n';
	return 0;
}
