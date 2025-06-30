#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> ops(m, vector<ll>(3));
    vector<ll>a(n+2);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++){
            cin >> ops[i][j];
        }
    }
    vector<ll> d1(m+2);
    int x, y;
    while(k--){
        cin >> x >> y;
        d1[x]++;
        d1[y+1]--;
    }
    for(int i=2; i<m+2; i++){
        d1[i] += d1[i-1];
    }
    for(int i=0; i < m; i++){
        ops[i][2] *= d1[i+1];
        // cout << ops[i][0] << " " << ops[i][1] << " " << ops[i][2] << endl;
    }
    vector<ll> d2(n+2);
    for(int i=0; i<m; i++){
        d2[ops[i][0]]+=ops[i][2];
        d2[ops[i][1]+1]-=ops[i][2];
    }
    a[1] += d2[1];
    for(int i=2; i<= n; i++){
        d2[i] += d2[i-1];
        a[i] += d2[i];
    }
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
}