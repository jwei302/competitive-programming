#include <bits/stdc++.h>
using namespace std;

// use stack when dealing with finding pairs.
int main(){
	int N;
	cin >> N;
	stack <int> s;
	vector<int> v;
	v.push_back(0);
	int nest = 0, symbol = 0, ind_i, ind_j;
	for(int i = 0; i < N; ++i){
		int dig;
		cin >> dig;
		if(dig == 1){
			s.push(1);
			if((int)s.size() > nest){
				nest = s.size();
				ind_i = i+1;
			}
		}else{
			s.pop();
			if(s.empty()){
				v.push_back(i+1);
			}
		}	
	}
	for(int i = 1; i < (int)v.size(); ++i){
		if(v[i] - v[i-1] > symbol){
			symbol = v[i] - v[i-1];
			ind_j = v[i-1] + 1;
		}
	}		
	cout << nest << " " << ind_i << " " << symbol  << " " << ind_j << endl;
}
