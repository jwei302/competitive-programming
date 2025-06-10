#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<int> prime_factors(int n){
    vector<int> res;
    for(int i=2; i*i<=n; i++){
        if(n % i == 0)
            res.push_back(i);
    }
    return res;
}
void solve(){
    int n, m;
    cin >> n >> m;
    if(n==1){
        cout << "YES\n";
        return;
    }
    if(n <= m){
        cout << "NO\n";
        return;
    }
    vector<int> check = prime_factors(n);
    if(check.empty()){
        cout << "YES\n";
        return;
    }
    for(int i=0; i<check.size(); i++){
        if(check[i] <= m){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}