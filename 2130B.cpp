#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rew(x) for(int i = 0; i < x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif

const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;
#define PI 3.141592653589

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    ll total = accumulate(all(a), 0LL);

    if (s < total || s == total + 1) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int x : a) {
            if (x == 0) ++c0;
            else if (x == 1) ++c1;
            else ++c2;
        }
        bool first = true;
        while (c0--) { cout << (first ? "" : " ") << 0; first = false; }
        while (c2--) { cout << (first ? "" : " ") << 2; first = false; }
        while (c1--) { cout << (first ? "" : " ") << 1; first = false; }
    } else {
        cout << -1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}

/*
   Author: SONIT RAJ
   created: 21:41:48 31-07-2025
*/
