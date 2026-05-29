/*
   Author: SONIT RAJ
    created: 18:57:29 27-05-2026
*/


#include<bits/stdc++.h>
using namespace std;


// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")
#define int  long long
const int mod = 1e9 + 7;


int dp[10][101];
int c[101][101];
void pre(){
    for(int i=0;i<=100;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}


int f(int idx,int len,vector<int>&a){
    if(idx>=10){
        return (len==0);
    }
    if(dp[idx][len]!=-1)return dp[idx][len];
    int ans=0;
    if(idx==0){
        for(int k=a[idx];k<len;k++){
            int temp=(c[len-1][k]*f(idx+1,len-k,a))%mod;
            ans=(ans+temp)%mod;
        }
    }
    else{
        for(int k=a[idx];k<=len;k++){
            int temp=(c[len][k]*f(idx+1,len-k,a))%mod;
            ans=(ans+temp)%mod;
        }
    }
    return dp[idx][len]=ans;
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>digit(10,0);
    int sum=0;
    for(int i=0;i<10;i++){
        cin>>digit[i];
        sum+=digit[i];
    }
    if(sum>n){
        cout<<0;
        return;
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=sum;i<=n;i++){
        int temp=f(0,i,digit);
        ans=(ans+temp)%mod;
    }
    cout<<ans;



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int _=1;
    while(_--){
        solve();
    }
}