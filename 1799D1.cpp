/*
   Author: SONIT RAJ
    created: 00:08:06 05-07-2025
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

int f(vector<int>&a,vector<int>&c,vector<int>&h,int i,int j,int n,vector<vector<int>>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
        int s1;
        int s2;
        int first=1e8;
        int second=1e8;
        s1=(i-1>=0)?a[i-1]:0;
        s2=j;
        if(s1==a[i]){
            first=h[a[i]]+f(a,c,h,i+1,j,n,dp);
            return dp[i][j]=first;
        }
        else if(s2==a[i]){
            second=h[a[i]]+f(a,c,h,i+1,s1,n,dp);
            return dp[i][j]=second;
        }
        else{
            first=c[a[i]]+f(a,c,h,i+1,s1,n,dp);
            second=c[a[i]]+f(a,c,h,i+1,s2,n,dp);
            return dp[i][j]=min(first,second);
        }
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>c(k+1,0);
    for(int i=1;i<=k;i++){
        cin>>c[i];
    }
    vector<int>h(k+1,0);
    for(int i=1;i<=k;i++){
        cin>>h[i];
    }
    vector<vector<int>>dp(n,vector<int>(k+1,-1LL));
    cout<<f(a,c,h,0,0,n,dp);



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