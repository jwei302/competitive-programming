#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5;
int N, M, C, t[MAX], lb, rb, mid;

//binary search the answer

bool ok(int T){
	int tmpM = M, cnt, pos=0, cur;
	while(tmpM--&&pos<N){
		cnt = 0;
		cur = t[pos];
		for(; pos < N && cnt < C && t[pos] < cur+T; ++pos, ++cnt);
	}
	return pos==N;
}

int main(){
	ifstream cin("convention.in");
	ofstream cout("convention.out");
	cin >> N >> M >> C;
	for(int i = 0; i < N; ++i){
		cin >> t[i];
	}
	sort(t, t+N);
	lb = 0, rb = 1e9;
	for(int i = 0; i < 30; ++i){
		mid = (lb+rb)/2;
		ok(mid)?rb = mid:lb = mid;
	}
	cout << lb <<'\n';
	return 0;
}

