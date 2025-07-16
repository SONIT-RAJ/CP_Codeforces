/*
   Author: SONIT RAJ
    created: 22:57:42 15-07-2025
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

bool f(string &a,string &b,vector<vector<vector<int>>>&dp,int &n,int i,int up,int left){
    if(i>=n){
        if(up==1 && left==0){
            return true;
        }
        return false;
    }
    if(dp[i][up][left]!=-1)return dp[i][up][left];
    if(left==0){
        if(up==0){
            if(a[i]<='2'){
                if(f(a,b,dp,n,i+1,0,0)){
                    return dp[i][up][left]=true;
                }
                return dp[i][up][left]=false;
            }
            else{
                if(f(a,b,dp,n,i,1,1)){
                    return dp[i][up][left]=true;
                }
                return dp[i][up][left]=false;
            }
        }
        else{
            if(b[i]<='2'){
                if(f(a,b,dp,n,i+1,1,0)){
                    return dp[i][up][left]=true;
                }
                return dp[i][up][left]=false;
            }
            else{
                if(f(a,b,dp,n,i,0,1)){
                    return dp[i][up][left]=true;
                }
                return dp[i][up][left]=false;
            }
        }
    }
    else{
        if(up==0){
            if(a[i]<='2'){
                return dp[i][up][left]=false;
            }
            else{
                if(f(a,b,dp,n,i+1,0,0)){
                    return dp[i][up][left]=true;
                }
                return dp[i][up][left]=false;
            }
        }
        else{
            if(b[i]<='2'){
                return dp[i][up][left]=false;
            }
            else{
                if(f(a,b,dp,n,i+1,1,0)){
                    return dp[i][up][left]=true;
                }
                return dp[i][up][left]=false;
            }
        }
    }
}

void solve(){

    int n;
    cin>>n;
    string a;
    string b;
    cin>>a;
    cin>>b;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
    if(f(a,b,dp,n,0,0,0)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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