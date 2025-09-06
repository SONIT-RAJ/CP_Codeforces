/*
   Author: SONIT RAJ
    created: 22:53:30 06-09-2025
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

int f(vector<int>&a,vector<vector<int>>&b,vector<vector<vector<int>>>&dp,int i,int j,int k){
    if(i>=b.size() || j>=b[0].size() || k>=a.size()){
        return 0;
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(a[k]==b[i][j]){
        dp[i][j][k]=( (f(a,b,dp,i,j+1,k)) || (f(a,b,dp,i+1,j,k))  || !(f(a,b,dp,i+1,j+1,k+1)));
    }
    else{
        dp[i][j][k]=((f(a,b,dp,i,j+1,k))||(f(a,b,dp,i+1,j,k)));
    }
    return dp[i][j][k];
}

void solve(){

    int l,m,n;
    cin>>l>>n>>m;
    vector<int>a(l);
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    vector<vector<int>>b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(l,-1)));
    if(f(a,b,dp,0,0,0)){
        cout<<"T";
    }
    else{
        cout<<"N";
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