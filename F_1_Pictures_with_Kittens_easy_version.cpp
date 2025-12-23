#include <bits/stdc++.h>
using namespace std;

static const long long NEG = (long long)-1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[i][j] = maximum sum using first i elements
    // with exactly j picks still remaining
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, NEG));

    // Base case: before taking anything, we need x picks
    dp[0][x] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < x; j++) {
            for (int p = 1; p <= k; p++) {
                if (i - p < 0) break;
                if (dp[i - p][j + 1] == NEG) continue;
                dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + a[i - 1]);
            }
        }
    }

    long long ans = NEG;
    // Last pick must be within last k positions
    for (int i = max(0, n - k + 1); i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    if (ans < 0) ans = -1;
    cout << ans << '\n';

    return 0;
}
