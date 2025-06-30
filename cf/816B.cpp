#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> t(2e5 + 2);
    int a, b;
    while(n--){
        cin >> a >> b;
        t[a]++;
        t[b+1]--;
    }
    for(int i=1; i<=2e5+1; i++){
        t[i] += t[i-1];
    }
    t[1] = t[1] >= k;
    for(int i=2; i<=2e5+1; i++){
        t[i] = t[i-1] + (t[i] >= k);
    }
    while(q--){
        cin >> a >> b;
        cout << t[b] - t[a-1] << endl;
    }
    return 0;
}