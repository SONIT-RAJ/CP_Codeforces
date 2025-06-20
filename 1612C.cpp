#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;

// Find the smallest m in [1, hi] such that f(m) >= target
// Assumes f is non-decreasing in m
ll binary_search_smallest(ll hi, ll target, function<ll(ll)> f) {
    ll lo = 1, ans = hi;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid) >= target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll k, x;
    cin >> k >> x;

    // Total emotes in the increasing half (1 + 2 + ... + k)
    ll sum_inc = k * (k + 1) / 2;
    if (x <= sum_inc) {
        // Binary search m in [1..k]: m*(m+1)/2 >= x
        auto f_inc = [&](ll m) { return m * (m + 1) / 2; };
        ll m = binary_search_smallest(k, x, f_inc);
        cout << m;
        return;
    }

    // Otherwise, subtract the increasing half
    x -= sum_inc;

    // Total emotes in the decreasing half ((k-1) + ... + 1)
    ll sum_dec = k * (k - 1) / 2;
    if (x >= sum_dec) {
        cout << (2 * k - 1);
        return;
    }

    // Binary search m in [1..k-1]: sum of first m of decreasing part >= x
    // f_dec(m) = m*k - m*(m+1)/2
    auto f_dec = [&](ll m) { return m * k - m * (m + 1) / 2; };
    ll m2 = binary_search_smallest(k - 1, x, f_dec);
    cout << (k + m2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}