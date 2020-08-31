#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define pb push_back;
#define mp make_pair;

int T;
string s;

string solve(){
	cin >> s;
	string ans = "YES";
	int N = s.size()/2;
	map <char, int> mp1;
	map <char, int> mp2;
	for(int i = 0; i < N; ++i){
		mp1[s[i]]++;
	}
	if(s.size() % 2 == 1){

		for(int i = s.size()-1; i > N; i--){
			mp2[s[i]]++;
		}
	}else{
		for(int i = s.size()-1; i >= N; --i){
			mp2[s[i]]++;
		}
	}
	for(auto a: mp1){
		if(mp1[a.first] != mp2[a.first]){
			ans = "NO";
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--){
		cout << solve() << endl;
	}
	return 0;
}
