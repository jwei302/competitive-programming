/*
ID: jeffrey88
PROG: runround
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll m;

bool ok(ll n){
	bool vis[10] ={0};
	while(n){
		if(n%10==0||vis[n%10]){
			return 0;
		}
		vis[n%10] = 1;
		n/=10;
	}
	return 1;
}

bool check(ll n){
	string num = to_string(n);
	int pos = 0;
	set<int> s;
	for(int cur = 0; cur < (int)num.size(); ++cur){
		int cnt = num[pos]-'0';
		for(int i = 0; i < cnt; ++i){
			pos = (pos+1)%(int)num.size();
		}
		if(cur == (int)num.size()-1){
			if(pos==0) return 1;
			else return 0;
		}
		if(s.count(num[pos]-'0')){
			return 0;
		}
		s.insert(num[pos]-'0');
	}
	return 1;
}
		
int main(){
	ifstream cin("runround.in");
	ofstream cout("runround.out");
	cin >> m;
	while(1){
		m++;
		if(ok(m)){
			if(check(m)){
				cout << m << '\n';
				return 0;
			}
		}
		else{
			while(m++&&!ok(m));
			m--;
		}
	}	
}
