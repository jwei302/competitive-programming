#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    char c;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    vector<int> row_cnt(n);
    vector<int> col_cnt(m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> c;
            a[i][j] = c=='.';
            row_cnt[i] += a[i][j];
            col_cnt[j] += a[i][j];
        }
    }
    int ans = m+n-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = min(ans, row_cnt[i] + col_cnt[j]-a[i][j]);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        solve();
    }
}