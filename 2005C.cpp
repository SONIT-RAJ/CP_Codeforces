/*
   Author: SONIT RAJ
    created: 00:23:02 22-08-2025
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

int f(vector<string>&a,string &s,vector<vector<int>>&dp,int i,int j){
    if(i>=a.size()){
        return -2*j;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=f(a,s,dp,i+1,j);
    int take=0;
    int j2=j;
    for(int k=0;k<a[i].size();k++){
        if(a[i][k]==s[j2]){
            take++;
            j2=(j2+1)%5;
        }
        else if(a[i][k]=='n' || a[i][k]=='a' || a[i][k]=='r' || a[i][k]=='e' || a[i][k]=='k'){
            take--;
        }
    }
    return dp[i][j]=max(dp[i][j],take+f(a,s,dp,i+1,j2));
}

void solve(){

    int n,m;
    cin>>n>>m;
    string s="narek";
    vector<string>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<int>>dp(n,vector<int>(5,-1));
    cout<<f(a,s,dp,0,0);




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