//sort + brute force
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 50, MAX = 1e9+5;
vector<pair<ll, ll>> op;
vector<pair<ll, ll>> North, East;
vector<bool> aliveE;
ll N, x, y;
char d;
map<pair<ll, ll>, ll> mp;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.second < b.second;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(ll i = 0; i < N; ++i){
		cin >> d >> x >> y;
		op.push_back(make_pair(x, y));
		mp[op[i]] = -1;
		if(d=='N')
			North.push_back(make_pair(x, y));
		else
			East.push_back(make_pair(x, y));
	}
	sort(North.begin(), North.end());
	sort(East.begin(), East.end(), cmp);
	aliveE.resize(East.size(), 1);
	for(ll i = 0; i < North.size(); ++i){
		for(ll j = 0; j < East.size(); ++j){
			//cout << North[i].first << " " << North[i].second << " " << East[j].first << " " << East[j].second << '\n';
			if(!aliveE[j] || East[j].first > North[i].first || East[j].second < North[i].second)
				continue;
			if(North[i].first - East[j].first > East[j].second - North[i].second){
				mp[East[j]] = North[i].first - East[j].first;
				aliveE[j] = 0;
			}
			else if(North[i].first - East[j].first < East[j].second - North[i].second){
				mp[North[i]] = East[j].second - North[i].second;
				break;
			}
		}
	}
	for(ll i = 0; i < N; ++i)
		mp[op[i]] != -1 ? cout << mp[op[i]] << '\n' : cout << "Infinity\n";
	return 0;
}
