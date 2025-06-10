#include <iostream>
using namespace std;

#define ll long long

ll total(ll mid, ll k){
    if(mid > k){
        return k*k - (2*k-1 - mid)*(2*k-mid)/2;
    }
    else{
        return mid*(mid+1)/2;
    }
}
void solve(){
    ll k, x;
    cin >> k >> x;
    if(k*k< x){
        cout << 2*k-1 << endl;
        return;
    }
    ll left =0, right = 2*k-1;
    while(left < right){
        ll mid = (left + right + 1)/2;
        ll sum = total(mid, k);
        if(sum < x){
            left = mid;
        }
        else{
            right = mid-1;
        }
    }
    cout << right + 1 << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}