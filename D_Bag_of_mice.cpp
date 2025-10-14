/*
   Author: SONIT RAJ
    created: 19:09:44 14-10-2025
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

double f(vector<vector<double>>&dp,double w,double b){
    if(w<=0)return 0.0L;
    if(b<=0)return 1.0L;
    if(dp[w][b]>-0.5)return dp[w][b];
    double p1=(b+w-2>0)?((double)b/(b+w))*(((double)b-1)/(b+w-1))*(((double)b-2)/(b+w-2)*f(dp,w,b-3)+((double)w/(b+w-2))*f(dp,w-1,b-2)):0.0;
    return dp[w][b]=((double)w/(w+b))+p1;
}

void solve(){

    int w,b;
    cin>>w>>b;
    vector<vector<double>>dp(w+1,vector<double>(b+1,-1.0));
    cout << fixed << setprecision(9) << f(dp, w, b);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}