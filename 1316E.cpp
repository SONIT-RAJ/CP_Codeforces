/*
   Author: SONIT RAJ
    created: 13:30:29 04-08-2025
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

int f(int i,int k,int bit,vector<int>&a,vector<vector<int>>&b,vector<vector<vector<int>>>&dp){
    if(i>=a.size())return 0;
    if(dp[bit][k][i]!=-1)return dp[bit][k][i];
    int audi=(k==0)?0:a[i]+f(i+1,k-1,bit,a,b,dp);
    int player=0;
    for(int j=0;j<b[0].size();j++){
        if((bit&(1<<j))==0){
            player=max(player,b[i][b[0].size()-1-j]+f(i+1,k,bit|(1<<j),a,b,dp));
        }
    }
    int skip=f(i+1,k,bit,a,b,dp);
    return dp[bit][k][i]=max({player,audi,skip});
}

void solve(){

    int n,p,k;
    cin>>n>>p>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>b(n,vector<int>(p));
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cin>>b[i][j];
        }
    }
    vector<vector<vector<int>>>dp(1<<p,vector<vector<int>>(k+1,vector<int>(n,-1)));
    cout<<f(0,k,0,a,b,dp);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}