#include <iostream>
using namespace std;

#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;
    while(n > 1){
        if(n % m == 0){
            cout << "YES\n";
            return;
        }
        n %= m;
    }
    cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}