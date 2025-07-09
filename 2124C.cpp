/*
   Author: SONIT RAJ
    created: 18:22:59 08-07-2025
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
 int lcm(int a,int b){
    return a*b/(__gcd(a,b));
 }

void solve(){

    int n;
    cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int x=1;
    for(int i=0;i<n-1;i++){
        if(b[i+1]%b[i]){
            x=lcm(x,b[i]/__gcd(b[i],b[i+1]));
        }
    }
    cout<<x;



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