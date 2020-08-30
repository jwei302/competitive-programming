/* ID:jeffrey88
LANG: C++
PROG: gift1
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	int n; fin >> n;
	string arr[10];
	map <string, int> mp;
	for (int i = 0; i < n; ++i){
		fin >> arr[i];
		mp[arr[i]] = 0;
	}
	for(int i = 0; i < n; ++i){
		string s; fin >> s;
		int a, b; fin >> a >> b;
		if (b==0) continue;
		mp[s] -= (a/b)*b;
		for(int i = 0; i < b; ++i){
			string str; fin >> str;
			mp[str] += a/b;
		}
	}
	for(int i = 0; i < n; ++i){
		fout << arr[i]<< " " <<mp[arr[i]]  << endl;
	}		
}
