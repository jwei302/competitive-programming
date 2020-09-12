#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e4;
int N, K, a[mxN], lb, rb, mid;

bool ok(int R){
	int pos = 0, tmpK = K;
	while(tmpK--&&pos<N){
		int range = a[pos] + 2*R;
		while(pos < N && a[pos] <= range){
			pos++;
		}
	}
	return pos==N;			
}
int main(){
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	cin >> N >> K;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a+N);
	lb = 0, rb = 1e9;
	for(int i = 0; i < 30; ++i){
		mid = (lb+rb)/2;
		ok(mid)?rb=mid:lb=mid;
	}
	cout << lb+1 << '\n';
	return 0;
}

