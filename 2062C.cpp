/*
   Author: SONIT RAJ
    created: 20:30:31 09-04-2025
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
    int sum=0;
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    maximum=max(maximum,sum);
    reverse(a.begin(),a.end());
    sum=0;
    for(int i=1;i<a.size();i++){
        b.push_back(a[i]-a[i-1]);
        sum+=b.back();
    }



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