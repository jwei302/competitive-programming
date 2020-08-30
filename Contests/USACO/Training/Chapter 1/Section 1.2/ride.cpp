/* ID:jeffrey88
LANG: C++
PROG: ride
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	string a, b;
	cin >> a >> b;
	int product1 = 1;
	int product2 = 1;
	for (int i = 0; i < a.size(); i++)
		product1 *= a[i]-'A'+1;
	for (int i = 0; i < b.size(); i++)
		product2 *= b[i]-'A'+1;
	cout << (product1%47 == product2%47?"GO":"STAY") << endl;
}
