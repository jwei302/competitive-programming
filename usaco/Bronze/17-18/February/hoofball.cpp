#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e2, INF = 1e9+5;
int N, a[mxN], pass[mxN];

int closest(int pos){
	if(pos&&pos<N-1){
		int ind, mn = INF;
		for(int i = pos-1; i >= 0; --i){
			if(a[pos]-a[i]<=mn){
				mn = a[pos]-a[i];
				ind = i;
			}
			else
				break;
		}
		return a[pos+1]-a[pos]<mn?pos+1:ind;
	}
	else if(!pos)
		return pos+1;
	else if(pos>=N-1)
		return pos-1;
}
int main(){
	ifstream cin("hoofball.in");
	ofstream cout("hoofball.out");
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a+N);
	int ans = 0;
	for(int i = 0; i < N; ++i)
		pass[closest(i)]++;
	for(int i = 0; i < N; ++i){
		if(!pass[i])
			ans++;
		if(i<closest(i)&&closest(closest(i))==i&&pass[i]==1&&pass[closest(i)]==1)
			ans++;

	}
	cout << ans << '\n';
	return 0;
}

