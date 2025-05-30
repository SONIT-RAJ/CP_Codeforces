/*
   Author: SONIT RAJ
    created: 11:39:51 13-05-2025
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

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        cout<<"YES";
        return;
    }
    int pre1;
    int pre2=__gcd(a[1],a[0]);
    int problem=-1;
    for(int i=2;i<n;i++){
        pre1=__gcd(a[i],a[i-1]);
        if(pre2<=pre1){
            pre2=pre1;
        }
        else{
            problem=i;
            break;
        }
    }
    if(problem==-1 || problem==n-1){
        cout<<"YES";
        return;
    }
    for(int i=problem+1;i<n;i++){
        if(i==problem+1){
            pre1=__gcd(a[i],a[i-2]);
        }
        else{
            pre1=__gcd(a[i],a[i-1]);
        }
        if(pre2<=pre1){
            pre2=pre1;
        }
        else{
            break;
        }
        if(i==n-1){
            cout<<"YES";
            return;
        }
    }
    for(int i=problem;i<n;i++){
        if(i==problem){
            pre1=__gcd(a[i],a[i-2]);
            pre2=(i>=3)?__gcd(a[i-2],a[i-3]):0;
        }
        else{
            pre1=__gcd(a[i],a[i-1]);
        }
        if(pre2<=pre1){
            pre2=pre1;
        }
        else{
            break;
        }
        if(i==n-1){
            cout<<"YES";
            return;
        }
    }
    for(int i=problem-1;i<n;i++){
        if(i==problem-1){
            pre1=(i>=2)?__gcd(a[i],a[i-2]):0;
            pre2=(i>=3)?__gcd(a[i-2],a[i-3]):0;
        }
        else{
            pre1=__gcd(a[i],a[i-1]);
        }
        if(pre2<=pre1){
            pre2=pre1;
        }
        else{
            break;
        }
        if(i==n-1){
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";




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