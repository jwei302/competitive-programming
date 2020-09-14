#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
int x[mxN], N, Q, a, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for(int i = 0; i < N; ++i){
		cin >> x[i];
	}
	for(int i = 1; i < N; ++i){
		x[i] ^= x[i-1];
	}
	while(Q--){
		cin >> a >> b;
		a--, b--;
		if(a==0){
			cout << x[b] << '\n';
		}
		else{
			cout << (x[a-1]^x[b])<< '\n';
		}
	}
	return 0;
}
