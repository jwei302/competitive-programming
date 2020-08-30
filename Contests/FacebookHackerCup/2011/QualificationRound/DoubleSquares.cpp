#include <bits/stdc++.h>
using namespace std;

int n, x;

bool isSquare(int a, int b){
	return a*a==b;
}
int solve(){
	int ans = 0;
	for(int i = 0; i * i <= x/2; ++i){
		if( isSquare((int)sqrt(x-i*i), x-i*i))
			ans++;
	}
	return ans;
}
int main(){
	ifstream cin ("double_squares_input.txt");
	ofstream cout ("double_squares_output.txt");
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> x;
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
