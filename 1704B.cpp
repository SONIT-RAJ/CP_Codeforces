/*
   Author: SONIT RAJ
    created: 20:57:30 28-03-2025
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

    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    int minimum=INT_MIN;
    int maximum=INT_MAX;
    int flag=1;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0 && maximum<a[i]-x){
            count++;
            minimum=a[i]-x;
            maximum=a[i]+x;
        }
        else if(i!=0 && minimum>a[i]+x){
            count++;
            minimum=a[i]-x;
            maximum=a[i]+x;
        }
        else{
            minimum=max(minimum,a[i]-x);
            maximum=min(maximum,a[i]+x);
        }

    }
    cout<<count;




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