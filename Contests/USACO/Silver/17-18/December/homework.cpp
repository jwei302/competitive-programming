#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5;
int N, a[mxN];

//prefix sums

int main(){
	ifstream cin("homework.in");
	ofstream cout("homework.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
	}
	for(int i = 1; i < N; ++i){
		a[i] += a[i-1];
	}
	vector<pair<double, int>> ans;
	for(int i = 0; i < N-2; ++i){
		ans.push_back({(double)(a[N-1]-a[i])/(double)(N-1-i), i+1});
	}
	sort(ans.rbegin(), ans.rend());
	for(int i = 0; i < (int)ans.size(); ++i){
		if(i==0){
			cout << ans[i].second;
		}
		else{
			if(ans[i].first==ans[0].first){
				cout << " " << ans[i].second;
			}
			else{
				cout << '\n';
				break;
			}
		}
	}	
	return 0;
}

