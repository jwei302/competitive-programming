/*
ID: jeffrey88
PROG: beads
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

string process(string s, int n){
	string str = "";
	str += s.substr(n);
	if( n != 0 ){
		str += s.substr(0, n);
	}
	return str;
}

int count(string s){
	char prev;
	int res = 0;
	for(int i = 0; i < s.length(); ++i){
		if( s[i] == 'w'){
			res++;
		}else{
			prev = s[i];
			for(int j = i; j < s.length(); ++j){
				if( s[j] == prev || s[j] =='w'){
					res++;
				}else{
					break;
				}
			}
			break;
		}
	}
	for(int i = s.length()-1; i >= 0; --i){
		if(s[i] == 'w')
			res++;
		else{
			prev = s[i];
			for(int j = i; j >= 0; --j){
				if(s[j] == prev || s[j] == 'w')
					res++;
				else
					break;
			}
			break;
		}
	}
	if(res > s.length()){
		res = s.length();
	}
	return res;
}
int main(){
	ifstream cin("beads.in");
	ofstream cout("beads.out");
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		string str = process(s, i);
		ans = max(count(str), ans);
	}
	cout << ans << endl;
}
