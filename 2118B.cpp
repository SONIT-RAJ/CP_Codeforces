/*
   Author: SONIT RAJ
    created: 10:00:19 13-06-2025
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
    cout<<2*n-2;
    for(int i=2;i<n;i++){
        cout<<i<<" "<<1<<" "<<i<<endl;
        cout<<i<<" "<<i+1<<" "<<n<<endl;
    }
    cout<<1<<" "<<2<<" "<<n<<endl;
    cout<<n<<" "<<1<<" "<<n<<endl;




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