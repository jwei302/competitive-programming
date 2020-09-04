#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3; 
int n, m;
string a[mxN];
 
bool e(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.';
}
void dfs(int i, int j){
	a[i][j] = '#';
	if( e(i+1, j)) dfs(i+1, j);
	if( e(i, j+1)) dfs(i, j+1);
	if( e(i-1, j)) dfs(i-1, j);
	if( e(i, j-1)) dfs(i, j-1);
}
 
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if( e(i, j)){ 
				dfs(i, j), ans++;
			}	
		}
	}
	cout << ans << '\n';
 
}
