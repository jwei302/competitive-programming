#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int N;
string s;
 
void solve(){
	cin >> N >> s;
	vector<int> len;
	int cur = 1, ans = 0;
	for(int i = 1; i < s.size(); ++i){
		if(s[i]==s[i-1])
			cur++;
		else{
			len.push_back(cur);
			cur = 1;
		}
	}
	len.push_back(cur);
	stack<int> st;
	for(int i = len.size()-1; i >= 0; --i)
		if(len[i]>1)
			st.push(i);
	for(int i = 0; i < len.size(); ++i){
		if(len[i]==0)
			continue;
		ans++;
		if(len[i]==1){
			if(st.size()){
				while(st.size()&&st.top()<i)
					st.pop();
				if(st.size()){
					len[st.top()]--;
					if(len[st.top()]==1)
						st.pop();
				}
				else{
					len[i] = 0;
					if(i < len.size()-1)
						len[i+1] = 0;
				}
			}
			else{
				len[i] = 0;
				if(i < len.size()-1)
					len[i+1] = 0;
			}
		}
		else
			len[i] = 0;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
