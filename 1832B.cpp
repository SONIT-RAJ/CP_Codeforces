/*
   Author: SONIT RAJ
    created: 20:21:46 27-03-2025
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
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    vector<int>p(n);
    p[0]=a[0];
    for(int i=1;i<n;i++){
        p[i]=a[i]+p[i-1];
    }
    long long minimum = LLONG_MAX;

    for(int i=0;i<k;i++){
        minimum=min(minimum,p[0+2*(k-i)-1]+p[n-1]-p[n-1-i]);
    }
    minimum=min(minimum,p[n-1]-p[n-1-k]);
    cout<<sum-minimum;
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