/*
ID: jeffrey88
LANG: C++11
PROG: dualpal
*/
#include <bits/stdc++.h>
using namespace std;

string convert(int base, int a){
	string res = "";
	while(a){
		res = to_string(a%base) + res;
		a /= base;
	}
	return res;
}

bool isPal(string a){
	if( a[0] == '0' || a.back() == '0')
		return false;
	for(int i = 0; i < a.size()/2; ++i)
		if( a[i] != a[a.size()-1-i])
			return false;
	return true;
}

int main(){
	ifstream cin ("dualpal.in");
	ofstream cout ("dualpal.out");
	int n, s;
	cin >> n >> s;
	int cnt = 0;
	while(cnt < n){
		s++;
		int base_cnt = 0;
		for(int i = 2; base_cnt < 2 && i <= 10; ++i){
			string str = convert(i, s);
			if( isPal(str))
				base_cnt++;
		}
		if( base_cnt == 2 ){
			cout << s << '\n';
			cnt++;
		}
	}
}




