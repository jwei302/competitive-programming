/*
ID: jeffrey88
LANG: C++11
PROG: palsquare
*/
#include <bits/stdc++.h>
using namespace std;

map<int, string> conversion;

bool isPalindrome(string a){
	for(int i = 0; i < a.size()/2; ++i){
		if(a[i] != a[a.size()-1-i])
			return false;
	}
	return true;
}

string convert(int base, int a){
	string ans = "";
	while(a){
		ans = conversion[a%base] + ans;
		a /= base;
	}
	return ans;
}
int main(){
	ifstream cin ("palsquare.in");
	ofstream cout ("palsquare.out");
	int B;
	cin >> B;
	for(int i = 0; i < 20; ++i){
		if ( i < 10 ){
			conversion[i] = to_string(i);
		}else{
			conversion[i] = char('A'+ i-10);
		}
	}

	for(int i = 1; i <= 300; ++i ){
		string s = convert(B, i);
		string squared = convert(B, (int)pow(i, 2));
		if(isPalindrome(squared))
			cout << s << " " << squared << endl;
	}
}


