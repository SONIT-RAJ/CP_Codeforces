/*
   Author: SONIT RAJ
    created: 20:26:43 27-03-2025
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

int nearestPowerOf2(int N) {
    if (N == 0) return 0; // Edge case

    // Convert all bits below the highest set bit to 1
    N |= (N >> 1);
    N |= (N >> 2);
    N |= (N >> 4);
    N |= (N >> 8);
    N |= (N >> 16);

    // The nearest power of 2 is (N + 1) >> 1
    return (N + 1) >> 1;
}

void solve(){

    int n;
    cin>>n;
    int flag=0;
    int required = nearestPowerOf2(n-1);
    for(int i=1;i<n;i++){
        if(i>=required && flag==0){
            cout<<0<<" ";
            flag=1;
        }
        cout<<i<<" ";
    }
    if(flag==0){
        cout<<0;
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