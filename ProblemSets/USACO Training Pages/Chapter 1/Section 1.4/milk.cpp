/*
ID: jeffrey88
LANG: C++11
PROG: milk
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin ("milk.in");
	ofstream cout ("milk.out");
	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<pair<int, int>> cost(m);
	for(int i = 0; i < m; ++i)
		cin >> cost[i].first >> cost[i].second;
	sort(cost.begin(), cost.end());
	int index = 0;
	while(n){
		int units = min(n, cost[index].second);
		ans += cost[index].first * units;
		n -= units;
		index++;
	}
	cout << ans << '\n';
}

