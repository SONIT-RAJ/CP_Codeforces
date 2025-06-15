/*
   Author: SONIT RAJ
    created: 11:11:36 15-06-2025
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

    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    int ans=(1<<31)-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans&=a[i];
    }
    vector<int>j(31,n);
    for(int i=0;i<=30;i++){
        for(int k=0;k<n;k++){
            int p=1<<i;
            if ((a[k] & p) == p){
                j[i]--;
            }
        }
    }
    for(int i=30;i>=0;i--){
        if(j[i]>0 && x>=j[i]){
            x-=j[i];
            ans+=(1<<i);
        }
    }
    cout<<ans;





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