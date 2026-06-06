/*
   Author: SONIT RAJ
    created: 23:39:37 06-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int f(vector<int>&a,vector<vector<vector<int>>>&dp,int &k,int i,int g,int c){
    if(i>=a.size()){
        return g==0;
    }
    if(i>0){
        c+=g*(a[i]-a[i-1]);
    }
    if(c>k)return 0;
    if(dp[i][g][c]!=-1)return dp[i][g][c];
    long long ans=0;
    long long val=f(a,dp,k,i+1,g+1,c);//new group and didn't close it
    ans=(ans+val)%mod;

    val=f(a,dp,k,i+1,g,c);//new group and close it
    ans=(ans+val)%mod;

    if(g>0){
        val=(1ll*g*f(a,dp,k,i+1,g,c))%mod;//old group and didn't close it
        ans=(ans+val)%mod;

        val=(1ll*g*f(a,dp,k,i+1,g-1,c))%mod;//old group and close it
        ans=(ans+val)%mod;
    }

    return dp[i][g][c]=ans;
}


// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
    cout<<f(a,dp,k,0,0,0);




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