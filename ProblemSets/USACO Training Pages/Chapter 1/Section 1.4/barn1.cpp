/*
ID: jeffrey88
LANG: C++11
PROG: barn1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin ("barn1.in");
	ofstream cout ("barn1.out");
	int m, s, c;
	cin >> m >> s >> c;
	vector<int> cows(c);
	for(int i = 0; i < c; ++i)
		cin >> cows[i];
	sort(cows.begin(), cows.end());
	vector<int>gap;
	for(int i = 1; i < c; ++i){
		gap.push_back(cows[i] - cows[i-1]);
	}
	sort(gap.rbegin(), gap.rend());	
	int ans = cows.back() - cows[0]+1;
	for(int i = 0; i < min(m-1, (int)gap.size()); ++i){
		ans -= gap[i] - 1;
	}
	cout << ans << endl;

}
