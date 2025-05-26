/*
   Author: SONIT RAJ
    created: 23:38:42 22-05-2025
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
    map<int,int>last;
    for(int i=0;i<n;i++){
        cin>>a[i];
        last[a[i]]++;
    }
    int ans=n;
    map<int,pair<int,int>>mpp;
    map<int,int>idx;
    for(int i=0;i<n;i++){
        if(mpp.find(a[i])==mpp.end()){
            mpp[a[i]].first=i;
        }
        else{
            int d=i-idx[a[i]]-1;
            if(d>=mpp[a[i]].first){
                mpp[a[i]].second=mpp[a[i]].first;
                mpp[a[i]].first=d;
            }
            else if(d>=mpp[a[i]].second){
                mpp[a[i]].second=d;
            }
        }
        last[a[i]]--;
        if(last[a[i]]<=0){
            if(n-i-1>=mpp[a[i]].first){
                mpp[a[i]].second=mpp[a[i]].first;
                mpp[a[i]].first=n-i-1;
            }
            else if(n-i-1>=mpp[a[i]].second){
                mpp[a[i]].second=n-i-1;
            }
            int big=max(mpp[a[i]].first/2,mpp[a[i]].second);
            ans=min(ans,big);
        }
        idx[a[i]]=i;
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