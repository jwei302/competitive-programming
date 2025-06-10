#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    vector<int> chat_count(m+1);
    vector<int> sent_count(n+1);
    int x, y;
    while(k--){
        cin >> x >> y;
        chat_count[y]++;
        sent_count[x]--;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]){
                sent_count[i]+=chat_count[j];
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << sent_count[i] << " ";
    }
    cout << endl;
}