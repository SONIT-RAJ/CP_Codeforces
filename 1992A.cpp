/*
   Author: SONIT RAJ
    created: 22:04:03 20-07-2025
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

    vector<int>a(3);
    cin>>a[0];
    cin>>a[1];
    cin>>a[2];
    sort(a.begin(),a.end());
    int e=5;
    while(e>0){
        if(a[0]==a[1] && a[1]==a[2]){
            a[0]+=min(e,1ll);
            e-=min(e,1ll);
            a[1]+=min(e,1ll);
            e-=min(e,1ll);
            a[2]+=min(e,1ll);
            e-=min(e,1ll);
        }
        else {
            if(a[0]<a[1]){
                int d=min(e,a[1]-a[0]);
                a[0]+=d;
                e-=d;
            }
            else if(a[1]<a[2]){
                if(e>0){
                a[1]++;
                e--;
                }
                if(e>0){
                    a[0]++;
                e--;
                }
            }
        }
    }
    cout<<a[0]*a[1]*a[2];




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}