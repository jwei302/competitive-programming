#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define ll long long

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    double cur_sum =0;
    for(int i=0; i<k; i++){
        cur_sum += a[i];
    }
    double total_sum = cur_sum;
    for(int i=k; i < n; i++){
        cur_sum += a[i] - a[i-k]; 
        total_sum += cur_sum;
    }
    cout << fixed << setprecision(6) << total_sum / (double) (n-k+1) << endl;
}