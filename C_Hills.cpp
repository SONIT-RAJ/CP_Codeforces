/*
   Author: SONIT RAJ
    created: 11:35:59 20-01-2026
*/



#include<bits/stdc++.h>
using namespace std;
#define int long long
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")

int dp[2][5001][2501];

void solve(){

    int n;
    cin>>n;
    vector<int>a(n+2);
    a[0]=-1e12;
    a[n+1]=-1e12;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int max_k=(n+1)/2;
    for(int b=0;b<2;b++){
        for(int i=0;i<5001;i++){
            for(int j=0;j<2501;j++){
                dp[b][i][j]=1e12;
            }
        }
    }
    for(int i=0;i<=n;i++){
        dp[0][i][0]=0;
    }
    dp[0][1][0]=0;
    dp[1][1][1]=(n==1 || a[1]>a[2])?0:a[2]-a[1]+1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=(i+1)/2;j++){
                dp[0][i][j]=min(dp[0][i-1][j],dp[1][i-1][j]);
                int right=(a[i+1]<a[i])?0:a[i+1]-a[i]+1;
                int left=(a[i-1]<a[i])?0:a[i-1]-a[i]+1;
                int back=min(a[i-2]-1,a[i-1]);
                int smart_left=(back<a[i])?0:back-a[i]+1;
                dp[1][i][j]=min(dp[0][i-2][j-1]+left+right,dp[1][i-2][j-1]+smart_left+right);
            }
        }
    for(int i=1;i<=max_k;i++){
        cout<<min(dp[1][n][i],dp[0][n][i])<<" ";
    }




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