/*
ID: jeffrey88
LANG: C++
PROG: transform
*/
#include <bits/stdc++.h>
using namespace std;

int n;

bool ninetydegree (vector<vector<int>> a, vector<vector<int>>b){
	vector<vector<int>> change(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			change[j][n-i-1] = a[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if( change[i][j] ^ b[i][j] )
				return false;
		}
	}

	return true;
}
bool oneeightydegree(vector<vector<int>> a, vector<vector<int>>b){	
	vector<vector<int>> change(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			change[n-i-1][n-j-1] = a[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if( change[i][j] ^ b[i][j])
				return false;
		}
	}
	return true;
}

bool twoseventydegree(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> change(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			change[n-j-1][i] = a[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if( change[i][j] ^ b[i][j]){
				return false;
			}
		}
	}
	return true;
}

bool reflection(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> change(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			change[i][n-1-j] = a[i][j];
		}
	}	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if ( change[i][j] ^ b[i][j] ){
				return false;
			}
		}
		cout<< '\n';
	}
	return true;
}

bool combo (vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> change(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			change[i][n-1-j] = a[i][j];
		}
	}	
	if(ninetydegree(change, b) || oneeightydegree(change, b) || twoseventydegree(change, b))
		return true;

	return false;
}

bool noChange(vector<vector<int>>a, vector<vector<int>>b){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if( a[i][j]^b[i][j] )
				return false;
		}
	}
	return true;
}

int main(){
	ifstream cin ("transform.in");
	ofstream cout ("transform.out");
	cin >> n;
	vector<vector<int>> initial(n, vector<int>(n)), end(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			char c;
			cin >> c;
			if( c == '@')
				initial[i][j] = true;
			else
				initial[i][j] = false;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			char c;
			cin >> c;
			if( c== '@')
				end[i][j] = true;
			else
				end[i][j] = false;
		}
	}
	if( ninetydegree(initial, end) )
		cout << "1" << '\n';
	else if ( oneeightydegree(initial, end))
		cout << "2" << '\n';
	else if ( twoseventydegree(initial, end))
		cout << "3" << '\n';
	else if ( reflection(initial, end))
		cout << "4" << '\n';
	else if ( combo(initial, end))
		cout << "5" << '\n';
	else if ( noChange(initial, end) ){
		cout << "6" << '\n';
	}
	else
		cout << "7" << '\n';
}
