#include <bits/stdc++.h>
using namespace std;

int isOperand(char ch){
	return ch>= 'A' && ch <= 'Z';
}
int precedence(char ch){
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '^')
		return 3;
	return -1;
}

void solve(){
	int n;
	string s;
	cin >> n >> s;
	stack<int> st;
	string ans;
	for(int i = 0; i < n; ++i){
		if(isOperand(s[i]))
			ans += s[i];
		else if(s[i] == '(')
			st.push('(');
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				char c = st.top();
				st.pop();
				ans += c;
			}
			if(st.top() == '(')
				st.pop();
		}else{
			while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
				char c= st.top();
				st.pop();
				ans += c;
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		char c = st.top();
		st.pop();
		ans += c;
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

