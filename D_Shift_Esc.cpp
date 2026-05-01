/*
   Author: SONIT RAJ
    created: 01:22:36 11-10-2025
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

void solve(){

    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m)));
    vector<vector<int>>p(n,vector<int>(m));
    int ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p[i][j]=LLONG_MAX;
            for(int k=0;k<m;k++){
                if(i==0 && j==0){
                    dp[i][j][k]=t*k+a[i][(j+k)%m];
                }
                else if(i==0){
                    dp[i][j][k]=a[i][(j+k)%m]+dp[i][j-1][k];
                }
                else if(j==0){
                    dp[i][j][k]=t*k+a[i][(j+k)%m]+p[i-1][j];
                }
                else{
                    dp[i][j][k]=min(dp[i][j-1][k],p[i-1][j]+t*k)+a[i][(j+k)%m];
                }
                p[i][j]=min(p[i][j],dp[i][j][k]);
                if(i==n-1 && j==m-1){
                    ans=min(ans,dp[i][j][k]);
                }
            }
        }
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