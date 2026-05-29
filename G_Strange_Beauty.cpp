/*
   Author: SONIT RAJ
    created: 08:38:24 29-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")

vector<vector<int>>f(2e5+1);

void pre(){
    for(int i=1;i<=2e5;i++){
        for(int j=i;j<=2e5;j+=i){
            f[j].push_back(i);
        }
    }
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>dp(2e5+1,0);
    int ans=0;
    for(int i=0;i<n;i++){
        int sz=f[a[i]].size();
        int val=0;
        for(int j=0;j<sz;j++){
            val=max(val,1+dp[f[a[i]][j]]);
        }
        dp[a[i]]=max(val,dp[a[i]]);
        ans=max(ans,dp[a[i]]);
    }
    cout<<n-ans;



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}