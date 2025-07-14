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

vector<int>pre(1e3+1,20);
void precompute(){
    pre[0]=-1;
    pre[1]=0;
    for(int i=1;i<=1e3;i++){
        for(int j=1;j<=1e3;j++){
            int b=i+i/j;
            if(b<=1e3){
                pre[b]=min(pre[b],pre[i]+1);
            }
        }
    }
}

int f(int i,vector<int>&b,vector<int>&c,vector<vector<int>>&dp,int k){
    if(i<0){
        return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    dp[i][k]=f(i-1,b,c,dp,k);
    if(k>=b[i]){
        dp[i][k]=max(dp[i][k],c[i]+f(i-1,b,c,dp,k-b[i]));
    }
    return dp[i][k];
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>b(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        b[i]=pre[b[i]];
        sum+=b[i];
    }
    k=min(k,sum);
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    cout<<f(n-1,b,c,dp,k);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    precompute();
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}