/*
   Author: SONIT RAJ
    created: 23:34:22 28-03-2025
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
    if (n == 0) return 0; // No set bits

    int pos = 63 - __builtin_clzll(n); // Find MSB position (0-based)  (very important)
    return (pos);
}

void solve(){

    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return;
    }
    int temp;
    if(b>a){
        temp=a;
        a=b;
        b=temp;
    }
    int s=firstSetBitFromLeft(a)-firstSetBitFromLeft(b);
    if(a!=(b<<s)){
        cout<<-1;
        return;
    }
    int count=0;
    count+=s/3;
    s%=3;
    count+=s/2;
    s%=2;
    count+=s/1;
    s%=1;
    cout<<count;


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