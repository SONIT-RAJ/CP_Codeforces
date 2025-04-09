/*
   Author: SONIT RAJ
    created: 21:38:47 09-04-2025
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

    int a,b;
    cin>>a>>b;
    int x;
    if((a-1)%4==0){
        x=a-1;
    }
    else if((a-1)%4==1){
        x=1;
    }
    else if((a-1)%4==2){
        x=a;
    }
    else if((a-1)%4==3){
        x=0;
    }
    if(x==b){
        cout<<a;
    }
    else if((b^x)!=a){
        cout<<a+1;
    }
    else{
        cout<<a+2;
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