/*
ID: jeffrey88
LANG: C++11
PROG: wormhole
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int partner[MAX_N+1], next_right[MAX_N+1];
bool cycle(){
	for(int start = 1; start <= N; ++start){
		int pos = start;
		for(int count = 0; count < N; ++count){
			pos = next_right[partner[pos]];
		}
		if( pos != 0){
			return true;
		}
	}
	return false;
}

int solve(){
	int total = 0;
	int i;
	for(i = 1; i <= N; ++i)
		if( partner[i] == 0) break;
	if( i > N){
		if( cycle()){
			return 1;
		}
		else
			return 0;
	}

	for(int j = i+1; j <= N; ++j){
		if(partner[j] == 0){
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;
		}
	}
	return total;
}

int main(){
	ifstream cin ("wormhole.in");
	ofstream cout ("wormhole.out");
	cin >> N;

	for(int i = 1; i <= N; ++i)
		cin >> X[i] >> Y[i];
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			if( X[j] > X[i] && Y[i] == Y[j]){
				if(next_right[i] == 0 || X[j] - X[i] < X[next_right[i]] - X[i]){
					next_right[i] = j;
				}
			}
		}
	}
	cout << solve() << '\n';
}

