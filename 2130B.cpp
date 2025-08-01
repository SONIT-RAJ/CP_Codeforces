/*
   Author: SONIT RAJ
    created: 20:14:07 31-07-2025
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

    int n,s;
    cin>>n>>s;
    vector<int>a(n);
    int sum=0;
    int t=0;
    int z=0;
    int o=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]==2)t++;
        if(a[i]==0)z++;
        if(a[i]==1)o++;
    }
    if(sum==s){
        cout<<-1;
        return;
    }
    if(sum>s){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        return;
    }
    if(sum+1==s){
        for(int i=0;i<z;i++)cout<<0<<" ";
        for(int i=0;i<t;i++)cout<<2<<" ";
        for(int i=0;i<o;i++)cout<<1<<" ";

        return;
    }
    cout<<-1;



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