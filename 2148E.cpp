/*
   Author: SONIT RAJ
    created: 12:36:21 14-09-2025
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

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    for(auto &x:mpp){
        if(x.second%k){
            cout<<0;
            return;
        }
        x.second/=k;
    }
    int i=0;
    int j=0;
    int ans=0;
    unordered_map<int,int>mpp2;
    while(j<n){
        mpp2[a[j]]++;
        while(i<=j && mpp2[a[j]]>mpp[a[j]]){
            mpp2[a[i]]--;
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    cout<<ans;




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