/*
   Author: SONIT RAJ
    created: 21:18:48 29-07-2025
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

int f(vector<int>&a,vector<int>&dp,int i,int &n){
    if(dp[i]!=-1)return dp[i];
    int maxi=1;
    for(int j=2*i;j<=n;j+=i){
        if(a[j]>a[i]){
            maxi=max(maxi,1+f(a,dp,j,n));
        }
    }
    return dp[i]=maxi;
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>dp(n+1,-1);
    int ans=1;
    for(int i=1;i<=n;i++){
        f(a,dp,i,n);
        ans=max(ans,dp[i]);
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