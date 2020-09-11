#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e4;
int N, cards[2*mxN+1], num;
vector<int> a, b;

//two pointers

int main(){
	ifstream cin("highcard.in");
	ofstream cout("highcard.out");
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> num;
		cards[num] = 1;
	}
	for(int i = 1; i <= 2*N; ++i){
		if(cards[i]){
			a.push_back(i);
		}
		else{
			b.push_back(i);
		}
	}
	int ans = 0;
	for(int i = 0, j = 0; i < N; ++i){
		if(a[i]>b.back()){
			break;
		}
		while(j <N&&b[j]<a[i]){
			j++;
		}
		if(b[j]>a[i]){
			ans++;
			j++;
		}
		else{
			break;
		}
	}
	cout << ans << '\n';		
	return 0;
}

