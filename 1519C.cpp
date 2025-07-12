/*
   Author: SONIT RAJ
    created: 11:57:53 07-06-2025
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
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>a[i][1];
    }
    sort(a.begin(),a.end(),greater<vector<int>>());
    int last=a[0][1];
    unordered_map<int,vector<int>>mpp;
    mpp[a[0][0]].push_back(a[0][1]);
    for(int i=1;i<n;i++){
        if(a[i][0]==a[i-1][0]){
            a[i][1]+=last;
        }
        last=a[i][1];
        mpp[a[i][0]].push_back(a[i][1]);
    }
    vector<int>ans(n+1,0);
    for(auto it=mpp.begin();it!=mpp.end();++it){
        int u=it->first;
        int s=mpp[u].size();
        for(int i=1;i<=s;i++){
            ans[i]+=(s%i==0)?mpp[u][s-1]:mpp[u][s-1-(s%i)];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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