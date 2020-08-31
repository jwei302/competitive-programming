#include <bits/stdc++.h>
using namespace std;

int solve(){
	int N, mod;
	string isIndian;
	cin >> N >> isIndian;
	if(isIndian == "INDIAN") mod = 200;
	else mod = 400;
	int total = 0;
	while(N--){
		string s;
		cin >> s;
		if(s == "CONTEST_WON"){
			int n; cin >> n;
			if(n < 20){
				total += 300 + 20 - n;
			}else{
				total += 300;
			}
		}
		else if(s == "TOP_CONTRIBUTOR"){
			total += 300;
		}
		else if(s == "BUG_FOUND"){
			int severity; cin >> severity;
			total += severity;
		}else{
			total += 50;
		}
	}
	return total/mod;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		cout << solve() << endl;
	}
	return 0;
}
