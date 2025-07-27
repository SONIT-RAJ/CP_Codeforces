/*
   Author: SONIT RAJ
    created: 08:38:07 26-07-2025
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

int f(vector<int>&a,vector<vector<int>>&dp,int i,int j,int &k){
    if(i>=a.size()){
        if(__builtin_popcountll(j)==k){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int p=f(a,dp,i+1,j&a[i],k);
    int np=f(a,dp,i+1,j,k);
    return dp[i][j]=(p+np)%M;
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(64,-1));
    if(k==6){
        cout<<f(a,dp,0,63,k)-1;
    }
    else{
        cout<<f(a,dp,0,63,k);
    }




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