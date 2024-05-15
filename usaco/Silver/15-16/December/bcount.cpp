#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
int N, Q, cow,cows[mxN][3], a, b;

int main(){
	ifstream cin("bcount.in");
	ofstream cout("bcount.out");
	cin >> N >> Q;
	for(int i = 0; i < N; ++i){
		cin >> cow;
		cow--;
		cows[i][cow]++;
	}
	for(int i = 1; i < N; ++i){
		for(int j = 0; j < 3; ++j){
			cows[i][j] += cows[i-1][j];
		}
	}
	while(Q--){
		cin >> a >> b;
		a--, b--;
		if(a==0){
			cout << cows[b][0] << " " << cows[b][1] << " " << cows[b][2] << '\n';
		}
		else{
			cout << cows[b][0] - cows[a-1][0] << " " << cows[b][1] - cows[a-1][1] << " " << cows[b][2] - cows[a-1][2] << '\n';
		}
	}
	return 0;
}

