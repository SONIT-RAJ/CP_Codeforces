/*
   Author: SONIT RAJ
    created: 23:16:16 14-10-2025
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

double f1(vector<vector<vector<double>>>&dp,int r,int s,int p){
    if(r<=0)return 0;
    if(s<=0 && p<=0)return 1;
    if(dp[r][s][p]>-0.5)return dp[r][s][p];
    double denom = (double)r * s + (double)s * p + (double)p * r;
    double one = 0.0, two = 0.0, three = 0.0;
    if(s > 0) one   = ((double)r * s) / denom * f1(dp, r, s-1, p);
    if(p > 0) two   = ((double)s * p) / denom * f1(dp, r, s, p-1);
    if(r > 0) three = ((double)p * r) / denom * f1(dp, r-1, s, p);
    return dp[r][s][p]=one+two+three;
}

double f2(vector<vector<vector<double>>>&dp,int r,int s,int p){
    if(s<=0)return 0;
    if(r<=0 && p<=0)return 1;
    if(dp[r][s][p]>-0.5)return dp[r][s][p];
    double denom = (double)r * s + (double)s * p + (double)p * r;
    double one = 0.0, two = 0.0, three = 0.0;
    if(s > 0) one   = ((double)r * s) / denom * f2(dp, r, s-1, p);
    if(p > 0) two   = ((double)s * p) / denom * f2(dp, r, s, p-1);
    if(r > 0) three = ((double)p * r) / denom * f2(dp, r-1, s, p);
    return dp[r][s][p]=one+two+three;
}

double f3(vector<vector<vector<double>>>&dp,int r,int s,int p){
    if(p<=0)return 0;
    if(s<=0 && r<=0)return 1;
    if(dp[r][s][p]>-0.5)return dp[r][s][p];
    double denom = (double)r * s + (double)s * p + (double)p * r;
    double one = 0.0, two = 0.0, three = 0.0;
    if(s > 0) one   = ((double)r * s) / denom * f3(dp, r, s-1, p);
    if(p > 0) two   = ((double)s * p) / denom * f3(dp, r, s, p-1);
    if(r > 0) three = ((double)p * r) / denom * f3(dp, r-1, s, p);
    return dp[r][s][p]=one+two+three;
}

void solve(){

    int r,s,p;
    cin>>r>>s>>p;
    vector<vector<vector<double>>>dp1(r+1,vector<vector<double>>(s+1,vector<double>(p+1,-1)));
    vector<vector<vector<double>>>dp2(r+1,vector<vector<double>>(s+1,vector<double>(p+1,-1)));
    vector<vector<vector<double>>>dp3(r+1,vector<vector<double>>(s+1,vector<double>(p+1,-1)));
    cout << fixed << setprecision(12) << f1(dp1,r,s,p)<<" ";
    cout << fixed << setprecision(12) << f2(dp2,r,s,p)<<" ";
    cout << fixed << setprecision(12) << f3(dp3,r,s,p);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}