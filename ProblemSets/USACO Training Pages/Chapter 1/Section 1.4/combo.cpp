/*
ID: jeffrey88
LANG: C++11
PROG: combo
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin ("combo.in");
	ofstream cout ("combo.out");
	int n;
	vector<int> a(3), b(3);
	cin >> n;
	for(int i = 0; i < 3; ++i)
		cin >> a[i];
	for(int i = 0; i < 3; ++i)
		cin >> b[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				int c1 = 0, c2 =0;
				vector<int> cmp = {i, j, k};
				for(int i1 = 0; i1 < 3; ++i1){
					if( abs(cmp[i1]-a[i1]) <= 2 || abs(cmp[i1]-a[i1]) >= (n-2)){
						c1++;
					}
				}
				for(int i1 = 0; i1 < 3; ++i1){
					if( abs(cmp[i1] - b[i1]) <= 2 || abs(cmp[i1] - b[i1]) >= (n-2)){
						c2++;
					}
				}
				if( c1 == 3 || c2 == 3){
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
}
