/*
ID: jeffrey88
PROG: lamps
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2;
int desired[mxN], button[4] = {1, 2, 3, 4};
vector<int> cur;
int N, C, pos, none = 1, ok;

int main(){
	ifstream cin("lamps.in");
	ofstream cout("lamps.out");
	memset(desired, -1, sizeof(desired));
	cin >> N >> C;
	cur = vector<int>(N);
	if(C%4){
		C %= 4;
	}
	else{
		C != 0 ? C = 4 : C = 0;
	}
	while(cin >> pos && pos > 0){
		desired[pos-1] = 1;
	}
	while(cin >> pos && pos > 0){
		desired[pos-1] = 0;
	}
	vector<vector<int>> subsets;
	for(int i = 0; i < (1 << 4); ++i){
		vector<int> subset;
		for(int j = 0; j < 4; ++j){
			if((int)subset.size()>=C){
				break;
			}
			if(i&(1<<j)){
				subset.push_back(button[j]);
			}
		}
		subsets.push_back(subset);
	}
	set<vector<int>> ans;
	for(auto subset: subsets){
		fill(cur.begin(), cur.end(), 1);
		for(int val: subset){
			if(val==1){
				for(int i = 0; i < N; ++i){
					cur[i] = !cur[i];
				}
			}
			if(val==2){
				for(int i = 0; i < N; i+=2){
					cur[i] = !cur[i];
				}
			}
			if(val==3){
				for(int i = 1; i < N; i+=2){
					cur[i] = !cur[i];
				}
			}
			if(val==4){
				for(int i = 0; 3*i < N; i++){
					cur[3*i] = !cur[3*i];
				}
			}
		}
		ok = 1;
		for(int i = 0; i < N; ++i){
			if(desired[i]==-1){
				continue;
			}
			if(desired[i]!=cur[i]){
				ok = 0;
				break;
			}
		}
		if(ok){
			ans.insert(cur);
			none = 0;
		}			
	}
	for(vector<int> v: ans){
		for(int i = 0; i < N; ++i){
			cout << v[i];
		}
		cout << '\n';
	}
	if(none){
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}
