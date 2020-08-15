#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	string s;
	cin >> s;
	ll cur = 1, ans = 0;
	for(int i = 1; i < s.size(); ++i){
		if(s[i]==s[i-1])
			cur++;
		else{
			ans = max(ans, cur);
			cur = 1;
		}
	}
	ans = max(ans, cur);
	cout << ans << '\n';
	return 0;
}

