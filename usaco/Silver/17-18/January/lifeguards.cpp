#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
pair<int, int> a[mxN], b[mxN];
int n;

//linear search for the lifeguard who covers least unoverlapped space
//remove this lifeguard and calculate answer

int main(){
	ifstream cin ("lifeguards.in");
	ofstream cout ("lifeguards.out");
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	for(int i = 0; i < n; ++i){
		b[i] = a[i];
	}
	for(int i = 0; i < n-1; ++i){
		if(b[i+1].first<b[i].second){
			swap(b[i+1].first, b[i].second);
		}
	}
	int min_coverage = INT_MAX, ind = -1;
	for(int i = 0; i < n; ++i){
		if(max(b[i].second-b[i].first, 0)<min_coverage){
			min_coverage = max(b[i].second-b[i].first, 0);
			ind = i;
		}
	}
	vector<pair<int, int>> shifts;
	int i;
	for(i = 0; i < n; ++i){
		if(i!=ind){
			shifts.push_back(a[i]);
			break;
		}
	}
	for(; i < n; ++i){
		if(i==ind) continue;
		if(shifts.back().second >= a[i].first){
			shifts.back().second = max(a[i].second, shifts.back().second);
		}
		else{
			shifts.push_back(a[i]);
		}
	}
	int ans = 0;
	for(i = 0; i < (int)shifts.size(); ++i){
		ans += shifts[i].second-shifts[i].first;
	}
	cout << ans << '\n';
}
