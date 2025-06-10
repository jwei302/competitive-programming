#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> indices(26);
    for(int i=0; i<n; i++){
        indices[s[i]-'a'].push_back(i+1);
    }
    int m;
    cin >> m;
    while(m--){
        string t;
        cin >> t;
        int max_pos = 0;
        vector<int> need(26);
        for(int i=0; i<t.size(); i++){
            need[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(need[i]){
                max_pos = max(max_pos, indices[i][need[i]-1]);
            }
        }
        cout << max_pos << endl;
    }
}