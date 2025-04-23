/*
   Author: SONIT RAJ
    created: 21:39:55 22-04-2025
*/


#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define int long long
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rew(x) for(int i = 0; i<x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;
#define PI 3.141592653589

void solve(){

    int n,k;
    cin>>n>>k;
    if(k>=n){
        cout<<1;
        return;
    }
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(n/i<=k){
                cout<<i;
                return;
            }
            else if(i<=k){
                ans=n/i;
            }
        }
    }

    cout<<ans;





}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}