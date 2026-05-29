/*
   Author: SONIT RAJ
    created: 19:58:26 29-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const int mod= 998244353;
const int M= 998244353;


// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")

int mul(int a, int b) { return (a * b) % mod; }
ll power(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = mod) { return power(a, m - 2, m); }



// ╭──────────────────────────────╮
// │        FACTORIAL ZONE        │
// ╰──────────────────────────────╯

const int MAXN=3e5;
int fact[MAXN+1], invFact[MAXN+1];
void precomp_fact() {
    fact[0] = invFact[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mod_inv(fact[i],mod);
    }
}
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r]));
}




// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,k;
    cin>>n>>k;
    map<int,int>mpp;
    map<int,int>mpp2;
    int ans=0;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        mpp[s]++;
        mpp[e+1]--;
        mpp2[s]++;
    }
    int temp=0;
    for(auto &x:mpp){
        temp+=x.second;
        int val=mpp2[x.first];
        if(temp>=k && val>0){
            for(int i=1;i<=val;i++){
                int ways=nCr(val,i);
                int value=nCr(temp-val,k-i);
                value=(value*ways)%mod;
                ans=(ans+value)%mod;
            }
        }
    }
    cout<<ans;




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    while(_--){
        solve();
    }
}