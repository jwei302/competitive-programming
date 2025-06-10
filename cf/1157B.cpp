#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> f(10);
    for(int i=1; i<10; i++){
        cin >> f[i];
    }
    bool has_not_stopped = true;
    for(int i=0; i<n; i++){
        if(s[i] - '0' < f[s[i]-'0'] ){
            s[i] = f[s[i]-'0']+'0';
            has_not_stopped = false;
        }
        else if(!has_not_stopped && s[i]-'0' == f[s[i]-'0']){
            continue;
        }
        else if(!has_not_stopped){
            break;
        }
    }
    cout << s << endl;
}