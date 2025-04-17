/*
   Author: SONIT RAJ
    created: 23:35:18 16-04-2025
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

    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    int answer=0;
    map<pair<int,int>,int> mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int pairx=(x-a[i]%x)%x;
        int pairy=a[i]%y;
        answer+=mpp[{pairx,pairy}];
        mpp[{a[i]%x,a[i]%y}]++;

    }
    cout<<answer;




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