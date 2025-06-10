#include <iostream>
#include <vector>

using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    while(b!= 0){
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> p(m);
    for(int i=0; i<n; i++)
        cin >> x[i];
    for(int i=0; i<m; i++)
        cin >> p[i];
    vector<ll> diffs;
    for(int i=1; i<n; i++)
        diffs.push_back(x[i] - x[i-1]);
    ll res = diffs[0];
    for(int i=1; i<diffs.size(); i++)
        res = gcd(res, diffs[i]);
    for(int i=0; i<m; i++){
        if(res % p[i]==0){
            cout << "YES\n" << x[0] << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "NO\n"; 
}