#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

bool works(ll a){
    while(a > 1){
        if(a % 2 == 0){
            a /= 2;
        }
        else if(a % 3 == 0){
            a /= 3;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll total_gcd = a[0];
    for(int i=1; i<n; i++){
        total_gcd = gcd(a[i], total_gcd);
    }
    // cout << total_gcd << endl;
    for(int i=0; i<n; i++){
        if(!works(a[i]/total_gcd)){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}