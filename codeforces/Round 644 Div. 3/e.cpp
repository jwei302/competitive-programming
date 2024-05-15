#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(arr[i][j] == '1' && i != n-1 && j != n-1 && arr[i][j+1] == '0' && arr[i+1][j] == '0'){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

