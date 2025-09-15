/*
   Author: SONIT RAJ
    created: 16:56:26 15-09-2025
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
const ll M = 998244353;
#define PI 3.141592653589

int f(vector<vector<int>>&dp,int &m,int i,int k){
    if(i<=1){
        if(k==0){
            return m;
        }
        else{
            return 0;
        }
    }
    if(k<0){
        return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    if(k>0){
        dp[i][k]=(f(dp,m,i-1,k)+f(dp,m,i-1,k-1)*(m-1))%M;
    }
    else{
        dp[i][k]=f(dp,m,i-1,k)%M;
    }
    return dp[i][k];
}

void solve(){

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    cout<<f(dp,m,n,k);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}