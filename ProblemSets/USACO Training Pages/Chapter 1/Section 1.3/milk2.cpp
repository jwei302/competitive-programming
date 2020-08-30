#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e3;
int n;
vector<vector<int>> a(mxN, vector<int>(2));
vector<pair<int, int>> merged;

int longest_continuous(){
	int mx = 0;
	for(int i = 0; i < merged.size(); ++i){
		mx = max(merged[i].second - merged[i].first, mx);
	}
	return mx;
}
int longest_idle(){
	int mx = 0;
	for(int i = 1; i < merged.size(); ++i){
		mx = max(merged[i].first - merged[i-1].second, mx);
	}
	return mx;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i][0] >> a[i][1];
	sort(a.begin(), a.begin()+n);
	pair<int, int> cur = {a[0][0], a[0][1]};
	for(int i = 1; i < n; ++i){
		if( a[i][0] >= cur.first && a[i][0] <= cur.second){
			cur.second = max(cur.second, a[i][1]);
		}else{
			merged.push_back(cur);
			cur = {a[i][0], a[i][1]};
		}
	}
	merged.push_back(cur);
	/*
	for(int i = 0; i < merged.size(); ++i){
		cout << merged[i].first << " " << merged[i].second << '\n';
	}
	*/
	cout << longest_continuous() << " " << longest_idle() << '\n';
}
