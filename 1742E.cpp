/*
   Author: SONIT RAJ
    created: 01:35:10 17-05-2025
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
    vector<int>a(n+1,0);
    int biggest=0;
    int smallest=LLONG_MAX;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        biggest=max(biggest,a[i]);
        smallest=min(smallest,a[i]);
    }
    vector<int>b(q);
    for(int i=0;i<q;i++){
        cin>>b[i];
    }
    map<int,int>mpp;
    int maxi=-1;
    for(int i=1;i<=n;i++){
        if(mpp.find(a[i]-1)==mpp.end()){
            if(a[i]-1>maxi){
                mpp[a[i]-1]=i-1;
                maxi=a[i]-1;
            }
        }
    }
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    vector<int>k1;
    k1.reserve(n);
    vector<int>k2;
    k2.reserve(n);
    for (auto &pair : mpp) {
        k1.emplace_back(pair.first);
        k2.emplace_back(pair.second);
    }
    for(int i=0;i<q;i++){
        if(b[i]<smallest){
            cout<<0<<" ";
        }
        else if(b[i]>=biggest){
            cout<<p[n]<<" ";
        }
        else{
            auto it = lower_bound(k1.begin(), k1.end(), b[i]);

        if (it != k1.end()) {
            cout<< p[k2[it - k1.begin()]]<<" ";
        }
        else {
            cout <<p[n]<<" ";
        }
        }
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