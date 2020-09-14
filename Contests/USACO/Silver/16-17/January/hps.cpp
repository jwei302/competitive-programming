#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
char a[mxN];
int N, psums[mxN][3];

//prefix sums

int count(char first, char second){
	int mx = 0, cur;
	for(int i = 0; i < N; ++i){
		cur = 0;
		if(first=='H'){
			cur += psums[i][2];
		}
		else if(first=='P'){
			cur += psums[i][0];
		}
		else{
			cur += psums[i][1];
		}
		if(second=='H'){
			cur += psums[N-1][2]-psums[i][2];
		}
		else if(second=='P'){
			cur += psums[N-1][0]-psums[i][0];
		}
		else{
			cur += psums[N-1][1]-psums[i][1];
		}
		mx = max(cur, mx);
	}
	return mx;
}
int main(){
	ifstream cin("hps.in");
	ofstream cout("hps.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < N; ++i){
		if(a[i]=='H'){
			psums[i][0]++;
		}
		else if(a[i]=='P'){
			psums[i][1]++;
		}
		else{
			psums[i][2]++;
		}
		if(i!=0){
			for(int j = 0; j < 3; ++j){
				psums[i][j]+=psums[i-1][j];
			}
		}
	}
	cout << max(count('H', 'P'), max(count('H', 'S'), max(count('P', 'S'), max(count('P', 'H'), max(count('S', 'H'), count('S', 'P')))))) << '\n';
	return 0;
}

