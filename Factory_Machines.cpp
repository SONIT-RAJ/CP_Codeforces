/*
   Author: SONIT RAJ
    created: 21:22:02 05-10-2025
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

bool c(vector<int>&a,int m,int &t,int &n){
    int temp=0;
    for(int i=0;i<n;i++){
        temp+=(m/a[i]);
        if(temp>=t)return true;
    }
    return false;;
}

void solve(){

    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=1;
    int h=1e18;
    int ans=h;
    while(l<=h){
        int m=l+(h-l)/2;
        if(c(a,m,t,n)){
            ans=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}