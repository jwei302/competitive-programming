/*
ID: jeffrey88
LANG: C++11
PROG: skidesign
*/
#include <bits/stdc++.h>
using namespace std;

int mxN = 1e3;
int N;
vector<int> a(mxN);

int main(){
	ifstream cin ("skidesign.in");
	ofstream cout ("skidesign.out");
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	int upper = INT_MIN;
	for(int i = 0; i < N; ++i)
		upper = max(a[i], upper);
	int amt = INT_MAX, cur;
	for(int i = 0; i <= upper-17; ++i){
		cur = 0;
		for(int j = 0; j < N; ++j){
			if( a[j] < i )
				cur += pow(i - a[j], 2);
			else if( a[j] > (i+17))
				cur += pow(a[j] - i-17, 2);
		}
		amt = min(cur, amt);
	}
	cout << amt << '\n';
}

		
	
