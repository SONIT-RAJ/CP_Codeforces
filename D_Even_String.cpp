/*
   Author: SONIT RAJ
    created: 19:26:07 29-10-2025
*/


#include<bits/stdc++.h>
using namespace std;
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,03,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")

// ╭──────────────────────────────╮
// │         ALIASES ZONE         │
// ╰──────────────────────────────╯
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
typedef unsigned long long ull;
typedef long double lld;

// ╭──────────────────────────────╮
// │         MACROS ZONE          │
// ╰──────────────────────────────╯
#define ll                long long
#define int               long long
#define eb                emplace_back
#define mp                make_pair
#define ff                first
#define ss                second
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define all(x)            x.begin(), x.end()
#define rall(x)           x.rbegin(),x.rend()
#define ins               insert
#define ln                '\n'
#define endl              "\n"
#define endlf             "\n" << flush;
#define yes               cout << "YES\n"
#define no                cout << "NO\n"
#define fr(i,n)           for(int i = 0; i < n; ++i)
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define getunique(v)      {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define NP(a)             next_permutation(all(a))
#define sz(x)             (int)((x).size())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

// ╭──────────────────────────────╮
// │         CONSTANTS            │
// ╰──────────────────────────────╯
const ll inf = 2e18 + 5;
const ll ninf = -2e18 - 5;
const ll mod =998244353;
const ll M=998244353;
const int MAXN = 1e6;
#define PI 3.1415926535897932384626433832795

// ╭──────────────────────────────╮
// │      MODULAR ARITHMETIC      │
// ╰──────────────────────────────╯
int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return (a * b) % M; }
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll power(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_inv(ll a, ll m = mod) { return power(a, m - 2, m); }
ll div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m


// ╭──────────────────────────────╮
// │        FACTORIAL ZONE        │
// ╰──────────────────────────────╯
int fact[MAXN+1], invFact[MAXN+1];
void precomp_fact() {
    fact[0] = invFact[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mod_inv(fact[i],M);
    }
}
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r]));
}

// ╭──────────────────────────────╮
// │      GLOBAL ZONE             │
// ╰──────────────────────────────╯
// ALWAYS USE cout << FIXED << SETPRECISION(value) <<NUMBER; WHILE OUTPUTTING FLOATS
// const int max_n = 1e7 + 3;
// int dp[max_n];
int f(vector<int>&a,vector<vector<int>>&dp,int s,int i){
    if(i>=26){
        if(s==0){
            return 1;
        }
        return 0;
    }
    if(s<0)return 0;
    if(dp[s][i]!=-1)return dp[s][i];
    if(a[i]==0){
        return dp[s][i]=(f(a,dp,s,i+1))%M;
    }
    return dp[s][i]=(f(a,dp,s,i+1)+f(a,dp,s-a[i],i+1))%M;
}


// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){
    vector<int>a(26);
    for(int i=0;i<26;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<26;i++){
        sum+=a[i];
    }
    vector<vector<int>>dp((sum)/2+1,vector<int>(26,-1));
    int ans=f(a,dp,(sum)/2,0);
    ans=(ans*fact[(sum+1)/2])%M;
    ans=(ans*fact[(sum)/2])%M;
    for(int i=0;i<26;i++){
        ans=(ans*invFact[a[i]])%M;
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
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}