#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3;
int N, Q;
char a[mxN][mxN];

//2D Prefix Sums

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> a[i][j];
	vector<vector<ll>> psums(N+1, vector<ll>(N+1));
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <=N; ++j)
			psums[i][j] = psums[i-1][j]+psums[i][j-1]-psums[i-1][j-1]+(a[i-1][j-1]=='*');
	while(Q--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << psums[x2][y2]-psums[x1-1][y2]-psums[x2][y1-1]+psums[x1-1][y1-1] << '\n';
	}
	return 0;
}

