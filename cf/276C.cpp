#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+2);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    vector<pair<ll, ll>> d(n+2);
    int l, r;
    vector<pair<ll, ll>> queries;
    while(q--){
        cin >> l >> r;
        queries.push_back({l, r});
        d[l].first++;
        d[r+1].first--;
    }
    for(int i=1; i<=n; i++){
        d[i].second = i;
        if(i > 1){
            d[i].first += d[i-1].first;
        }
    }
    sort(d.begin()+1, d.end()-1);
    sort(a.begin()+1, a.end()-1);
    vector<ll> v(n+1);
    for(int i=1; i<= n; i++){
        v[d[i].second] = a[i];
    } 
    for(int i=2; i<=n; i++){
        v[i] += v[i-1];
    }
    ll sum = 0;
    for(auto p: queries){
        sum += v[p.second]-v[p.first-1];
        // cout << "Sum: " << sum << endl;
    }
    cout << sum << endl;
    return 0;
}