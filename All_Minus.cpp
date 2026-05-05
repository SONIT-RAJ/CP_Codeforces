/*
   Author: SONIT RAJ
    created: 19:25:46 03-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
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
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n==1){
        if(a[0]==1){
            cout<<"Bob";
        }
        else{
            cout<<"Alice";
        }
        return;
    }

    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    if(mpp[0]>=2){
        cout<<"Alice";
        return;
    }
    string first="Alice";
    string second="Bob";
    if(mpp[0]==1){
        swap(first,second);
    }
    int t=1;
    for(auto &x:mpp){
        int key=x.first;
        int val=x.second;
        if(key==0)continue;
        if(key==t){
            t++;
            if(val>=2){
                cout<<second;
                return;
            }
        }
        else{
            cout<<first;
            return;
        }
    }
    cout<<second;



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}



