/*
   Author: SONIT RAJ
    created: 10:12:26 13-07-2025
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

    int n,m;
    cin>>n>>m;
    int two=0;
    int temp=n;
    while(temp%2==0){
        two++;
        temp/=2;
    }
    int five=0;
    temp=n;
    while(temp%5==0){
        five++;
        temp/=5;
    }
    int k=1;
    if(two>five){
        while(k*5<=m && five!=two){
            k*=5;
            five++;
        }
    }
    else if(five>two){
        while(k*2<=m && five!=two){
            k*=2;
            two++;
        }
    }
    while(k*10<=m){
        k*=10;
    }
    cout<<(m/k)*k*n;



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