#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
int N, a[mxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	stack<int> s;
	for(int i = 0; i < N; ++i){
		while(!s.empty()&&a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty())
			cout << 0 << " ";
		else
			cout << s.top()+1 << " ";
		s.push(i);
	}
	return 0;
}

