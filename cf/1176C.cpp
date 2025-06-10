#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long

int main(){
    unordered_map<int, int> mp = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int> counts(6);
    int i = 0;
    while(i < n){
        if(mp[a[i]] == 0){
            counts[0]++;
        }
        else{
            if(counts[mp[a[i]]-1] > counts[mp[a[i]]]){
                counts[mp[a[i]]]++;
            }
        }
        i++;
    }
    cout << n - counts[5] * 6 << endl;
}