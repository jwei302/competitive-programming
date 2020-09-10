#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3;
int N;
char a[mxN][mxN];
vector<vector<pair<int, int>>>cc;
vector<pair<int, int>> cur, ans;
bool vis[mxN][mxN];

void dfs(int i, int j){
	if(i<0||i>=N||j<0||j>=N||vis[i][j]||a[i][j]=='.'){
		return;
	}
	cur.push_back({i, j});
	vis[i][j] = 1;
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
}

int main(){
	ifstream cin("perimeter.in");
	ofstream cout("perimeter.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(!vis[i][j]&&a[i][j]=='#'){
				cur.clear();
				dfs(i, j);
				cc.push_back(cur);
			}
		}
	}
	pair<int,int> ans;
	for(vector<pair<int,int>>c:cc){
		pair<int,int> info;
		info.first = c.size();
		for(pair<int,int>ind:c){
			if(ind.first+1>=N||a[ind.first+1][ind.second]=='.'){
				info.second++;
			}
			if(ind.first-1<0||a[ind.first-1][ind.second]=='.'){
				info.second++;
			}
			if(ind.second+1>=N||a[ind.first][ind.second+1]=='.'){
				info.second++;
			}
			if(ind.second-1<0||a[ind.first][ind.second-1]=='.'){
				info.second++;
			}
		}
		if(info.first>ans.first){
			ans.first = info.first;
			ans.second = info.second;
		}
		if(info.first==ans.first){
			ans.second = min(ans.second, info.second);
		}
	}
	cout << ans.first << " " << ans.second << '\n';
		
	return 0;
}

