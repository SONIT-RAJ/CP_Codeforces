/*
   Author: SONIT RAJ
    created: 22:27:57 25-06-2026
*/


#include<bits/stdc++.h>
using namespace std;


// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")

const int mod = 1e9+7;



int f(vector<vector<int>>&a,vector<vector<vector<int>>>&dp,int n,int g,int mask,int t){
    if(mask==0){
        if(t==0)return 1;
        return 0;
    }
    if(t==0)return 1;
    if(dp[g][t][mask]!=-1)return dp[g][t][mask];
    long long ans=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))!=0 && t>=a[i][0] & a[i][1]!=g){
            int new_mask=(mask & ~(1 << i));
            ans=(ans+f(a,dp,n,a[i][1],new_mask,t-a[i][0]))%mod;
        }
    }
    return dp[g][t][mask]=ans;
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,t;
    cin>>n>>t;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    vector<vector<vector<int>>>dp(4,vector<vector<int>>(t+1,vector<int>(1<<n,-1)));
    cout<<f(a,dp,n,0,(1<<n)-1,t);




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    while(_--){
        solve();
    }
}