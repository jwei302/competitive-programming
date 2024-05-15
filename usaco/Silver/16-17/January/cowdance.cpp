#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9+7
const int mxN = 1e4;
int N, T, d[mxN], lb, rb, mid;

//binary search the answer and priority queue

bool ok(int K){
	int minTime = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < N; ++i){
		if((int)pq.size() == K){
			minTime = pq.top();
			pq.pop();
		}
		if(minTime+d[i]>T){
			return 0;
		}
		pq.push(minTime+d[i]);
	}
	return 1;
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

