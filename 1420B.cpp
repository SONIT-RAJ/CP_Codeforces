/*
   Author: SONIT RAJ
    created: 17:17:57 25-03-2025
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

int firstSetBitFromLeft(int n) {
    if (n == 0) return 0; // Edge case: No set bit
    return 32 - __builtin_clz(n); // For a 32-bit integer
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>bit(33);
    for(int i=0;i<n;i++){
        cin>>a[i];
        bit[firstSetBitFromLeft(a[i])]++;
    }
    int sum=0;
    for(int i=1;i<33;i++){
        int y=bit[i];
        sum+=y*(y-1)/2;
    }
    cout<<sum;




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