#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
int w[mxN], N;

//greedy, sort

int main(){
	ifstream cin("lemonade.in");
	ofstream cout("lemonade.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> w[i];
	}
	sort(w, w+N, greater<int>());
	int ans = 0;
	for(int i = 0; i < N; ++i){
		if(w[i]>=ans){
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

