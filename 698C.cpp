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

int f(int i,vector<int>&a,vector<vector<int>>&dp,int b){
    if(i>=a.size()){
        return 0;
    }
    if(dp[i][b]!=-1)return dp[i][b];
    if(a[i]==0){
        return dp[i][b]=1+f(i+1,a,dp,2LL);
    }
    else if(a[i]==1){
        if(b==1){
            return dp[i][b]=1+f(i+1,a,dp,2LL);
        }
        return dp[i][b]=min(1+f(i+1,a,dp,2LL),f(i+1,a,dp,1LL));
    }
    else if(a[i]==2){
        if(b==0){
            return dp[i][b]=1+f(i+1,a,dp,2LL);
        }
        return dp[i][b]=min(1+f(i+1,a,dp,2LL),f(i+1,a,dp,0LL));
    }
    else if(a[i]==3){
        int x=1+f(i+1,a,dp,2LL);
        int y;
        if(b==0){
            y=f(i+1,a,dp,1LL);
        }
        else if(b==1){
            y=f(i+1,a,dp,0LL);
        }
        else{
            y=min(f(i+1,a,dp,0LL),f(i+1,a,dp,1LL));
        }
        return dp[i][b]=min(x,y);
    }
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(3,-1));
    cout<<f(0,a,dp,2);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}