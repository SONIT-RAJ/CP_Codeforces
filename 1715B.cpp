/*
   Author: SONIT RAJ
    created: 13:14:51 26-03-2025
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

    int n,k,b,s;
    cin>>n>>k>>b>>s;
    if(b>(s/k)){
        cout<<-1;
        return;
    }
    if(b<(s-(n-1)*(k-1))/k){
        cout<<-1;
        return;
    }
    cout<<min(s,k*b+k-1)<<" ";
    s-=min(s,k*b+k-1);
    for(int i=1;i<n;i++){
        if(s>k-1){
        cout<<k-1<<" ";
        s-=k-1;
        }
        else{
            cout<<s<<" ";
            s-=s;
        }
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