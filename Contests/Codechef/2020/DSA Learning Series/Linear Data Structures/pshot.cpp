#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; string shot;
	cin >> n >> shot;
	int a = 0, b = 0, a_cnt = 0, b_cnt = 0, ans = 0;
	for(int i = 0; i < 2*n; ++i){
		i % 2 == 0 ? a_cnt++ : b_cnt++;
		if(i % 2 == 0 && shot[i] == '1'){
			a++;
		}else if (i % 2 == 1 && shot[i] == '1'){
			b++;
		}
		if(((b < a) && (n-b_cnt) < (a-b)) || (a < b && (n-a_cnt)< (b-a))){
			ans = i+1;
			break;
		}
	}
	if(!ans){
		cout << 2*n << endl;
	}else{
		cout << ans << endl;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
