#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        ll p = v[n / 2];
        if (p < l) p = l;
        if (p > r) p = r;
        ll ans = 0;
        for (ll x : v) ans += llabs(p - x);
        cout <<ans<<endl;
    }
    return 0;
}