#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
ll N, a[mxN];

//prefix sums

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll,ll>, ll> b){
	return a.first.first*b.first.second>a.first.second*b.first.first;
}

int main(){
	ifstream cin("homework.in");
	ofstream cout("homework.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
	}
	for(int i = 1; i < N; ++i){
		a[i] += a[i-1];
	}
	vector<pair<pair<ll, ll>, ll>> ans;
	for(int i = 0; i < N-2; ++i){
		ans.push_back({{a[N-1]-a[i], N-i-1}, i+1});
	}
	sort(ans.begin(), ans.end(), cmp);
	pair<ll, ll> best = ans[0].first;
	bool first = 1;
	for(int i = 0; i < (int)ans.size(); ++i){
		if(best.first*ans[i].first.second==best.second*ans[i].first.first){
			if(first){
				cout << ans[i].second;
				first = 0;
			}
			else{
				cout << " " << ans[i].second;
			}			
		}
		else{
			break;
		}
	}
	cout << '\n';
	return 0;
}

