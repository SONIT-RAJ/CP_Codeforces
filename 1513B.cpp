/*
   Author: SONIT RAJ
    created: 22:40:46 21-07-2025
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]!=a[1]){
        cout<<0;
        return;
    }
    int m=0;
    for(int i=0;i<n;i++){
        if(a[0]==a[i]){
            m++;
            continue;
        }
        if((a[i]&a[0])!=a[0]){
            cout<<0;
            return;
        }
    }
    int ans=1;
    ans=(ans*m)%M;
    ans=(ans*(m-1))%M;
    for(int i=n-2;i>=1;i--){
        ans=(ans*i)%M;
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