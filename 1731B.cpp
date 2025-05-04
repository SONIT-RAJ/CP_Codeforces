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

static const long long MOD   = 1000000007;
static const long long INV6  = 166666668;  // 6^(MOD-2) mod MOD
static const long long FACT  = 2022;

long long c(long long n) {
    // reduce n mod MOD to keep intermediate products small
    n %= MOD;
    long long n2 = (n * n) % MOD;     // n^2 mod
    long long n3 = (n2 * n) % MOD;    // n^3 mod

    // numerator = 4n^3 + 3n^2 - n  (mod MOD)
    long long num = ( (4 * n3) % MOD
                    + (3 * n2) % MOD
                    -  n
                    +  MOD        // ensure non-negative before final %
                   ) % MOD;

    // a_n = numerator * inv6 % MOD
    long long an = (num * INV6) % MOD;

    // final answer = 2022 * a_n % MOD
    return (FACT * an) % MOD;
}

void solve(){

    int n;
    cin>>n;
    cout<< c(n);



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