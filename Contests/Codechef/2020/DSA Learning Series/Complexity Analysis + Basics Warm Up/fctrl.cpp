#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int T;
int solve(){
	int num; 
	cin >> num;
	int res = 0;
	int mod = 5;
	while(num >= mod){
		res += num/mod;
		mod *= 5;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--){
		cout << solve() << endl;
	}
	return 0;
}
