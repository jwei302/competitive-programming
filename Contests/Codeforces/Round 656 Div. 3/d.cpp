#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

int recursion(const string &s, char c){
	int n = s.size();
	if(n == 1)
		return s[0] != c;
	int c1 = recursion(string(s.begin(), s.begin()+n/2), c+1);
	c1 += n/2 - count(s.begin()+n/2, s.end(), c);
	int c2 = recursion(string(s.begin()+n/2, s.end()), c+1);
	c2 += n/2 - count(s.begin(), s.begin()+n/2, c);
	return min(c1, c2);
}
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << recursion(s, 'a') << '\n';
}
int main(){
	FASTIO;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
