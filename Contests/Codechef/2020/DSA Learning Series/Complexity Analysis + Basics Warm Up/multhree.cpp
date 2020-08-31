#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

void solve(){
	ll K, d0, d1;
	cin >> K >> d0 >> d1;
	ll sum = d0+d1;
    ll c = (K-3)/4;
    
    ll c_sum = ((2*sum)%10) + ((4*sum)%10) + ((8*sum)%10) + ((6*sum)%10);
    ll total = 0;
    
    if(K==2)
        total = sum;
    
    else
    {
        total = sum + (sum%10) + (c*c_sum);
        ll left = (K-3) - (c*4);
        ll i, p=2;
        
        for(i=1; i<=left; i++)
        {
            total += (p*sum)%10;
            p = (2*p)%10;
        }
    }
    
    if(total%3==0)
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
}

int main(){
	int T; 
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
