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

int f(vector<int>&a,vector<int>&b,vector<vector<int>>&dp,int i,int fl){
    if(i>=a.size()){
        return 0;
    }
    if(fl==2){
        return max(f(a,b,dp,i+1,2),max(a[i]+f(a,b,dp,i+1,1),b[i]+f(a,b,dp,i+1,0)));
    }
    if(dp[i][fl]!=-1)return dp[i][fl];
    if(fl==0){
        return dp[i][fl]=max(a[i]+f(a,b,dp,i+1,1),f(a,b,dp,i+1,0));
    }
    else{
        return dp[i][fl]=max(b[i]+f(a,b,dp,i+1,0),f(a,b,dp,i+1,1));
    }
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<vector<int>>dp(n,vector<int>(2,-1));
    cout<<f(a,b,dp,0,2);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}