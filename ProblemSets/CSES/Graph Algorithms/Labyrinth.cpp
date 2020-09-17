#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e3;
int N, M, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char a[MAX][MAX];
bool vis[MAX][MAX], done = 0;

//bfs

bool ok(int i, int j){
	return i >= 0 && i < N && j >= 0 && j < M;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	map<pair<int,int>, pair<pair<int,int>, char>> mp;
	pair<int, int> start;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> a[i][j];
			if(a[i][j]=='A'){
				start.first = i, start.second = j;
			}
		}
	}
	queue<pair<int, int>> q;
	vis[start.first][start.second] = 1;
	q.push(start);
	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();
		for(int k = 0; k < 4; ++k){
			pair<int, int> v = {u.first+dx[k], u.second+dy[k]};
			if(ok(v.first, v.second)&&!vis[v.first][v.second]&&a[v.first][v.second]!='#'){
				char dir;
				if(dx[k]==1) dir = 'D';
				if(dx[k]==-1) dir = 'U';
				if(dy[k]==1) dir = 'R';
				if(dy[k]==-1) dir = 'L';
				mp[v] = {u, dir};
				if(a[v.first][v.second]=='B'){
					done = 1;
					string ans = "";
					while(1){
						ans += mp[v].second;
						v = mp[v].first;
						if(v.first==start.first&&v.second==start.second) break;
					}
					reverse(ans.begin(), ans.end());
					cout << "YES\n" << ans.length() << '\n' << ans << '\n';
					return 0;
				}
				vis[v.first][v.second] = 1;
				q.push(v);																		
			}
		}
	}
	if(!done){
		cout << "NO\n";
	}
	return 0;
}

