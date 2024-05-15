#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; 
	cin >> n;
	int arr[n];
	int even = 0, odd = 0, close = 0;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		if(arr[i] % 2 == 0) even++;
		else odd++;
	}
	sort(arr, arr+n);
	for(int i = 1; i < n; ++i){
		if(arr[i] - arr[i-1] == 1){
			close++;
		}
	}
	if((even % 2 == 0 && odd % 2 == 0) || ((even) % 2 == 1 && (odd) % 2 == 1 && close >= 1)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
