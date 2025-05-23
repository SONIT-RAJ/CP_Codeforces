/*
   Author: SONIT RAJ
    created: 12:29:15 27-03-2025
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

int fair(int n){
    int t=n;
    while(t!=0){
        if(t%10==0){
            t/=10;
        }
        else if(n%(t%10)!=0){
            return fair(n+1);
        }
        else{
            t/=10;
        }
    }
    return n;
}

void solve(){

    int n;
    cin>>n;
    cout<<fair(n);



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