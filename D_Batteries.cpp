/*
   Author: SONIT RAJ
    created: 21:27:12 09-10-2025
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

    ll n;
    cin >> n;
    for(int diff = 1; diff <= n-1; diff++) {
        for(int i = 1; i <= n; i++) {
            int j = i + diff;
            if(j > n) j -= n;
            cout << i << ' ' << j << endl;
            int ans;
            cin >> ans;
            if(ans == -1) exit(0);
            if(ans == 1) return;
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
        cout<<"\n";
    }
}