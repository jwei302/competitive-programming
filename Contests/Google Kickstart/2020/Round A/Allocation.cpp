#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
vector<int> a(mxN);

void solve(){
    int n, b, s=0;
    cin >> n >> b;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.begin()+n);
    
    for(int i = 0; i < n; ++i){
        s+=a[i];
        if(s>b){
            cout << i << '\n';
            return;
        }
    }
    cout << n << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
