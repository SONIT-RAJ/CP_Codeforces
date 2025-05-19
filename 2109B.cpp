#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll calculateTurns(ll n, ll m, ll a, ll b) {
    // Distance to closest border (row-wise and column-wise)
    ll rowRange = min(a, n - a + 1);
    ll colRange = min(b, m - b + 1);

    // Number of cuts = 1 (final step) + ceil(log2(rowRange)) + ceil(log2(colRange))
    ll turns = 1;
    turns += (ll)ceil(log2(rowRange));
    turns += (ll)ceil(log2(colRange));

    return turns;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << calculateTurns(n, m, a, b) << "\n";
    }

    return 0;
}
