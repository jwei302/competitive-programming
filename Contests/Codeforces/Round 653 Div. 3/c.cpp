#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	string str;
	cin >> n >> str;
	stack <int> s;
	int cnt = 0;
	for(int i = 0; i < str.size(); ++i){
		if( str[i] == '('){
			s.push(1);
		}else{
			if( s.empty())
				cnt++;
			else{
				s.pop();
			}
		}
	}
	cout << cnt << '\n';
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

