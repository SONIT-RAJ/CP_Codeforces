#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long

void CoderAbhi27() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<vector<int>> vec(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        ans += r[i] - l[i];
        vec[i] = {l[i] + r[i], l[i], r[i]};
    } // n
    sort(vec.rbegin(), vec.rend()); // n*logn

    for (int i = 0; i < n / 2; i++) {
        ans += vec[i][2];
    } // n/2
    for (int i = n / 2; i < n / 2 + n / 2; i++) {
        ans -= vec[i][1];
    } // n/2
    if (n % 2 == 0) {
        cout << ans << '\n';
        return;
    }

    int val = ans;
    for (int i = n - 2; i >= n / 2; i--) {
        val -= vec[i + 1][1];
        val += vec[i][1];
        ans = max(ans, val);
    } // n/2
    for (int i = n / 2 - 1; i >= 0; i--) {
        val += vec[i + 1][2];
        val -= vec[i][2];
        ans = max(ans, val);
    } // n/2
    cout << ans << '\n';
}

// tc : O(n*logn)
// sc : O(n)

int32_t main() {
    fastIO;

    int t = 1;
    cin >> t;
    while (t--) {
        CoderAbhi27();
    }
    return 0;
}