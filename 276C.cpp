/*
   Author: SONIT RAJ
    created: 20:09:49 02-06-2025
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
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end(),greater<int>());
    int sum=0;
    vector<int>d(n+2,0);
    while(q--){
        int l,r;
        cin>>l>>r;
        d[l]++;
        d[r+1]--;
    }
    for(int i=1;i<n+2;i++){
        d[i]+=d[i-1];
    }
    sort(d.begin()+1,d.begin()+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        sum+=d[i]*a[i];
    }
    cout<<sum;








}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}