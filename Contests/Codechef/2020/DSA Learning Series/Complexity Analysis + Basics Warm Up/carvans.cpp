#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int solve(){
	int N;
	cin >> N;
	vector<int> cars (N);
	int res = 0;
	int cur;
	for(int i = 0; i < N; ++i){
		cin >> cars[i];
		if(i == 0){
			cur = cars[i];
			res++;
		}else{
			if( cars[i] <= cur ){
				res++;
				cur = cars[i];
			}
		}
	}
	return res;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		cout << solve() << endl;
	}
	return 0;
}
