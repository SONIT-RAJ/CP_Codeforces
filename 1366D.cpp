/*
   Author: SONIT RAJ
    created: 00:34:24 03-07-2025
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

const int N = 1e7 + 1;
int spf[N]; // spf[i] will store smallest prime factor of i

void sieve() {
    for (int i = 0; i < N; i++) spf[i] = i; // Initially assume i is its own smallest prime factor

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i; // Update only if it's not updated before
                }
            }
        }
    }
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>ans(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i];
        int p=spf[a[i]];
        int d1=1;
        int x=a[i];
        while(x%p==0){
            x/=p;
            d1*=p;
        }
        int d2=a[i]/d1;
        if(d1>1 && d2>1 && __gcd(d1+d2,a[i])==1){
            ans[i][0]=d1;
            ans[i][1]=d2;
        }
        else{
            ans[i][0]=-1;
            ans[i][1]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i][0]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans[i][1]<<" ";
    }







}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    sieve();
    while(t--){
        solve();
    }
}