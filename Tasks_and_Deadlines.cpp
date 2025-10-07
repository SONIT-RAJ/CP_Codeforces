/*
   Author: SONIT RAJ
    created: 17:54:54 06-10-2025
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
    vector<int>a(n);
    int x;
    int p=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>x;
        p+=x;
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        a[i]=a[i]+a[i-1];
        p-=a[i];
    }
    cout<<p-a[0];


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}