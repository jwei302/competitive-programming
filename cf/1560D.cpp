#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long

vector<string> cmp;

int f(string num, string s){
    int res = 0;
    int n = num.size();
    int m = s.size();
    int i=0, j=0;
    while(i < n && j < m){
        if(num[i] == s[j]){
            i++, j++;
        }
        else{
            res++;
            i++;
        }
    }
    res += m - j + n - i;
    // cout << s << " " << res << endl;
    return res;
}

void solve(){
    int n;
    cin >> n;
    string num = to_string(n);
    int ans = num.size()+1;
    for(int i=0; i<cmp.size(); i++){
        ans = min(ans, f(num, cmp[i]));
    }
    cout << ans << endl;
}

int main(){
    ll num = 1;
    while(num < 1e18){
        cmp.push_back(to_string(num));
        num *= 2;
    }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}