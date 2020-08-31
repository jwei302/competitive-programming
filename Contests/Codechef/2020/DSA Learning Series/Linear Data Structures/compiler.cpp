#include <bits/stdc++.h>
using namespace std;

//use stack

void solve(){
	string s;
	cin >> s;
	stack<int> cnt;
	int ans = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		if(s[i] == '<')
			cnt.push(1);
		else if(s[i] == '>'){
			if(cnt.size() == 0){
				ans = i;
				break;
			}else{
				cnt.pop();
				if(cnt.size() == 0){
					ans = i;
				}
			}
		}
	}
	cout << ans << endl;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
