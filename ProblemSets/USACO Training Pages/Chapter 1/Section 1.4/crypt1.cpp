/*
ID: jeffrey88
LANG: C++11
PROG: crypt1
*/
#include <bits/stdc++.h>
using namespace std;

set<int> s;

bool works(string p1, string p2){
	string partial1 = to_string(stoi(p1) * (p2[1] - '0')), partial2 = to_string(stoi(p1) * (p2[0] - '0'));
	if( partial1.size() != 3 || partial2.size() != 3)
		return false;
	for(int i = 0; i < 3; ++i)
		if( !s.count(partial1[i]-'0') || !s.count(partial2[i]-'0'))
			return false;
	partial2 += '0';
	string product = to_string(stoi(partial1) + stoi(partial2));
	for(int i = 0; i < product.size(); ++i){
		if( !s.count(product[i] - '0') )
			return false;
	}
	return true;
}
int main(){
	ifstream cin ("crypt1.in");
	ofstream cout ("crypt1.out");
	int n;
	cin >> n;
	int cnt = 0;
	while( cnt < n ){
		int num;
		cin >> num;
		s.insert(num);
		cnt++;
	}
	int ans = 0;
	for(auto a: s){
		for( auto b: s){
			for(auto c: s){
				for(auto d: s){
					for(auto e: s){
						string p1 = to_string(a) + to_string(b) + to_string(c), p2 = to_string(d) + to_string(e);
						if(works(p1, p2))
							ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}

