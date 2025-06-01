/*
   Author: SONIT RAJ
   created: 09:35:36 01-06-2025
*/

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
//#define int long long  // Commented out to avoid confusion with shifts
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rew(x) for(int i = 0; i<x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
const ll inf = 2000000000000000000LL; // safer literal
const ll m= 998244353;
const ll M = 1e9 + 7;
#define PI 3.141592653589

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    ll cur = base % mod;
    while (exp > 0) {
        if (exp & 1) result = (result * cur) % mod;
        cur = (cur * cur) % mod;
        exp >>= 1;
    }
    return result;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> q[i];

    vector<pair<int,int>> pm(n), qm(n);
    pm[0] = {p[0], 0};
    qm[0] = {q[0], 0};

    for(int i = 1; i < n; i++) {
        if(p[i] > pm[i-1].first) {
            pm[i] = {p[i], i};
        } else {
            pm[i] = pm[i-1];
        }

        if(q[i] > qm[i-1].first) {
            qm[i] = {q[i], i};
        } else {
            qm[i] = qm[i-1];
        }
    }

    for(int i = 0; i < n; i++) {
        if(pm[i].first > qm[i].first) {
            cout << (modpow(2, pm[i].first, m) + modpow(2, q[i - pm[i].second], m)) % m << " ";
        }
        else if(pm[i].first < qm[i].first) {
            cout << (modpow(2, qm[i].first, m) + modpow(2, p[i - qm[i].second], m)) % m << " ";
        }
        else {
            if(q[i - pm[i].second] >= p[i - qm[i].second]) {
                cout << (modpow(2, pm[i].first, m) + modpow(2, q[i - pm[i].second], m)) % m << " ";
            } else {
                cout << (modpow(2, qm[i].first, m) + modpow(2, p[i - qm[i].second], m)) % m << " ";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}
