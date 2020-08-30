#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		string ans;
		int n;
		int mx = 0;
		cin >> n;
		++n;
		for(int j = 1; j <= n; ++j){
			string name;
			set<char> freq;
			getline(cin, name);
			int m = name.size();
			for(int i = 0; i < m; ++i){
				if(name[i] != ' ')
					freq.insert(name[i]);
			}
			if((int)freq.size() > mx){
				mx = freq.size();
				ans = name;
			} else if((int)freq.size() == mx){
				name < ans ? ans = name : ans = ans;
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
