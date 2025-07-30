/*
   Author: SONIT RAJ
    created: 22:51:30 29-07-2025
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

int f(vector<int>&a,vector<vector<int>>&dp,int i,int length){
    if(i>=a.size()){
        return 1;
    }

    if(dp[i][length]!=-1)return dp[i][length];

    int np=f(a,dp,i+1,length);

    int p=0;

    if((a[i])%(length+1)==0 && length<a.size()){
        p=f(a,dp,i+1,length+1);
    }

    return dp[i][length]=(p+np)%M;
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<f(a,dp,0,0)-1;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}