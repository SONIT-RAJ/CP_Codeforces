/*
   Author: SONIT RAJ
    created: 14:31:22 05-10-2025
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
    vector<vector<int>>a(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i;
    }
    vector<int>b(n);
    sort(a.begin(),a.end());
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}