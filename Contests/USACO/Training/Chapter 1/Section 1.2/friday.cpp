/*ID: jeffrey88
LANG: C++
PROG: friday
*/
#include <bits/stdc++.h>
using namespace std;

bool isLeap(int x){
	if ( x % 100 == 0) return x%400==0;
	else return x % 4==0;
}
int main(){
	ifstream cin ("friday.in");
	ofstream cout ("friday.out");
	int week[7] = {0,0,0,0,0,0,0};
	int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int n; cin >> n;
	int index = 2;
	for(int i = 1900; i < 1900 + n; ++i){
		if( isLeap(i) ) month[1] = 29;
		for(int j = 0; j < 12; ++j){
			for(int k = 1; k <= month[j]; ++k){
				if( k == 13 ){
					week[index % 7]++;
				}
				index++;
			}
		}
		month [1] = 28;
	}
	for(int i = 0; i < 7; ++i){
		if(i == 6) cout << week[i] <<'\n';
		else cout << week[i] << " ";
	}
}

