#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9+7
const int mxN = 1e4;
int N, T, d[mxN], lb, rb, mid, tmp[mxN];

//binary search the answer

bool ok(int K){
	int total = 0, curmn, nextmn = inf; 
	for(int i = 0; i < N; ++i){
		if(i < K){
			nextmn = min(tmp[i], nextmn);
		}
		tmp[i] = d[i];
	}
	int cnt = N-K+1, tmpK;
	while(cnt--){
		tmpK = K;
		curmn = nextmn;
		nextmn = inf;
		total += curmn;
		for(int j = 0; j < N && tmpK; ++j){
			if(tmp[j]){
				tmp[j] -= curmn;
				tmpK--;
			}
			if(tmp[j]!=0){
				nextmn = min(nextmn, tmp[j]);
			}
		}
	}
	total += *max_element(tmp, tmp+N);
	return total <= T;
}
int main(){
	ifstream cin("cowdance.in");
	ofstream cout("cowdance.out");
	cin >> N >> T;
	for(int i = 0; i < N; ++i){
		cin >> d[i];
	}
	lb = 0, rb = N;
	for(int i = 0; i < 15; ++i){
		mid = (lb+rb)/2;
		ok(mid)? rb = mid:lb = mid;
	}
	cout << rb << '\n';
	return 0;
}

