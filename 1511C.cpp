/*
   Author: SONIT RAJ
    created: 14:09:16 19-04-2025
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

    int n,q;
    cin>>n>>q;
    unordered_map<int,int>mpp;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(mpp[x]==0){
            mpp[x]=i;
        }
    }
    for(int i=0;i<q;i++){
        cin>>x;
        cout<<mpp[x]<<" ";
        for (auto& it : mpp) {
            if(it.second<mpp[x]){
                it.second++;
            }
        }
        mpp[x]=1;
    }





}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
        cout<<"\n";
    }
}