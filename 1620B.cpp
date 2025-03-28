/*
   Author: SONIT RAJ
    created: 13:24:05 26-03-2025
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

    int x,y;
    cin>>x>>y;
    int k1;
    cin>>k1;
    vector<int>a1(k1);
    for(int i=0;i<k1;i++){
        cin>>a1[i];
    }
    int k2;
    cin>>k2;
    vector<int>a2(k2);
    for(int i=0;i<k2;i++){
        cin>>a2[i];
    }
    int k3;
    cin>>k3;
    vector<int>a3(k3);
    for(int i=0;i<k3;i++){
        cin>>a3[i];
    }
    int k4;
    cin>>k4;
    vector<int>a4(k4);
    for(int i=0;i<k4;i++){
        cin>>a4[i];
    }
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    sort(a3.begin(),a3.end());
    sort(a4.begin(),a4.end());
    int maximum1=max(y*(a1[k1-1]-a1[0]),y*(a2[k2-1]-a2[0]));
    int maximum2=max(x*(a3[k3-1]-a3[0]),x*(a4[k4-1]-a4[0]));
    cout<<max(maximum1,maximum2);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}