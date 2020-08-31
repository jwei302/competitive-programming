#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	ll G, I, N, Q;
	cin >> G;
	while(G--){
		cin >> I >> N >> Q;
		if(N % 2 == 0){
			cout << N/2 << endl;
		}else{
			if(I == 1 && Q == 1){
				cout << N/2 << endl;
			}else if(I==1){
				cout << N - N/2 << endl;
			}else if(I == 2 && Q == 1){
				cout << N - N/2 << endl;
			}else{
				cout << N/2 << endl;
			}
		}
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
