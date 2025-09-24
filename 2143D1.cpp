/*
   Author: SONIT RAJ
    created: 20:29:43 17-09-2025
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

int f(vector<int>&a,vector<vector<vector<int>>>&dp,int r,int b,int i){
    if(i>=a.size())return 1;
    if(dp[r][b][i]!=-1)return dp[r][b][i];
    int Red=(r==0)?-1e9:a[r];
    int Blue=(b==0)?-1e9:a[b];
    int ans=0;
    if(a[i]<Red && a[i]<Blue){
        ans=f(a,dp,r,b,i+1)%M;
    }
    else if(a[i]<Red && a[i]>=Blue){

        ans=(f(a,dp,r,b,i+1)+f(a,dp,r,i,i+1))%M;
    }
    else if(a[i]<Blue && a[i]>=Red){

        ans=(f(a,dp,r,b,i+1)+f(a,dp,i,b,i+1))%M;
    }
    
    else{
        if(Red>=Blue){
            ans=(f(a,dp,r,b,i+1)+f(a,dp,i,b,i+1))%M;
        }
        else{
            ans=(f(a,dp,r,b,i+1)+f(a,dp,r,i,i+1))%M;
        }
    }
    return dp[r][b][i]=ans;
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
    cout<<f(a,dp,0,0,1);



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