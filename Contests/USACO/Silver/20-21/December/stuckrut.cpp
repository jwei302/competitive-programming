//sort + dfs
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3;
vector<pair<ll, ll>> North, East, op;
vector<bool> aliveE;
vector<ll> whoKillsN, whoKillsE;
vector<ll> adj[mxN];
ll N, x, y;
char c;
map<pair<ll, ll>, ll> mp;
map<ll, ll> kills;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.second < b.second;
}
ll children;
void dfs(ll u){
	for(ll v: adj[u]){
		children++;
		dfs(v);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll N;
	cin >> N;
	for(ll i = 0; i < N; ++i){
		cin >> c >> x >> y;
		op.push_back({x, y});
		mp[make_pair(x, y)] = i;
		if(c == 'N')
			North.push_back({x, y});
		else
			East.push_back({x, y});
	}
	sort(North.begin(), North.end());
	sort(East.begin(), East.end(), cmp);
	aliveE.resize(East.size(), 1);
	whoKillsN.resize(North.size(), -1);
	whoKillsE.resize(East.size(), -1);
	for(ll i = 0; i < N; ++i)
		kills[i] = -1;
	for(ll i = 0; i < North.size(); ++i){
		for(ll j = 0; j < East.size(); ++j){
			if(!aliveE[j] || East[j].first > North[i].first || East[j].second < North[i].second)
				continue;
			if(North[i].first - East[j].first < East[j].second - North[i].second){
				kills[mp[North[i]]] = mp[East[j]];
				break;
			}
			else if(North[i].first - East[j].first > East[j].second - North[i].second){
				kills[mp[East[j]]] = mp[North[i]];
				aliveE[j] = 0;
			}
		}
	}
	//for(ll i = 0; i < N; ++i)
		//cout << i+1 << " " << kills[i]+1 << '\n';
	for(ll i = 0; i < N; ++i){
		if(kills[i]==-1)
			continue;
		else
			adj[kills[i]].push_back(i);
	}
	for(ll i = 0; i < N; ++i){
		children = 0;
		dfs(i);
		cout << children << '\n';
	}
}
