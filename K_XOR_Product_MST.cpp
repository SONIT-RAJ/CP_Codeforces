#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353


int xorr(int k) {
    int n = k % 4;
    if (n == 0) return k;
    if (n == 1) return 1;
    if (n == 2) return k + 1;
    return 0;
}

void solve(){
    int n;
    cin >> n;

    int ans = 0;

    if (n > 1) ans += 6;
    if (n >= 5) ans -= 1;

    for (int i = n; i > max(2ll, n - 3); i--) {
        if (i & 1) continue; // skip odd
        ans = (ans + i * xorr(i)) % MOD;
    }

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;
    cin >> tt;
    while (tt--) {
        solve();
        cout<<"\n";
    }
}
