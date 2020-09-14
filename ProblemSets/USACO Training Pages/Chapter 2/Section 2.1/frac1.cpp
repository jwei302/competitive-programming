/*
ID: jeffrey88
PROG: frac1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ifstream cin("frac1.in");
	ofstream cout("frac1.out");
	int n;
	cin >> n;
	map<double, string> mp;
	for(int i = 0; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			if(j==0) continue;
			if(!mp.count((double)i/(double)j)){
				mp[(double)i/(double)j] = to_string(i)+'/'+to_string(j);
			}
		}
	}
	for(auto key:mp){
		cout << key.second << '\n';
	}
	return 0;
}

