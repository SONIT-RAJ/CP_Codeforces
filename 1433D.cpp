/*
   Author: SONIT RAJ
    created: 11:18:20 25-05-2025
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
    int idx=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            if(a[0]!=a[i]){
                idx=i+1;
            }
        }
    }
    if(idx==-1){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(int i=1;i<n;i++){
        if(a[i]==a[0]){
            cout<<i+1<<" "<<idx<<"\n";
        }
        else{
            cout<<1<<" "<<i+1<<"\n";
        }
    }



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}