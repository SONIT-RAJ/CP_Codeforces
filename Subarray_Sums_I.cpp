/*
   Author: SONIT RAJ
    created: 13:34:48 08-10-2025
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i-1];
    }
    unordered_map<int,int>mpp;
    int ans=0;
    for(int i=0;i<=n;i++){
        if(mpp.count(p[i])){
            ans+=mpp[p[i]];
        }
        mpp[k+p[i]]++;
    }
    cout<<ans;
    //tc - O(n)
    //sc - O(n)


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}