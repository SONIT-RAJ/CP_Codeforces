/*
   Author: SONIT RAJ
    created: 19:13:34 13-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353



// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>c(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    vector<int>dp(n+1,0);
    for(int i=n-2;i>=0;i--){
        dp[i]=dp[i+1];
        if(a[i]<=0 || a[i]>n)continue;
        for(int j=i+a[i];j<n;j++){
            int up=j-i-1;
            if(a[i]-1<=up){
                int ways=c[up][a[i]-1];
                int temp=(ways*(dp[j+1]+1))%mod;
                dp[i]=(dp[i]+temp)%mod;
            }
        }
    }
    cout<<dp[0];



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}