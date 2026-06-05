#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    string s, t;
    cin >> s >> t;

    char t1 = t[0];
    char t2 = t[1];

    // dp[i][j][cnt] -> max subsequences after processing i characters,
    // using j modifications, with 'cnt' occurrences of t1 so far.
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
    dp[0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int cnt = 0; cnt <= i; ++cnt) {
                if (dp[i][j][cnt] == -1) continue;

                int cur_val = dp[i][j][cnt];

                // Approach: We explicitly try converting s[i] into every meaningful state:
                // State A: Keep s[i] exactly as it is
                {
                    int nj = j;
                    int ncnt = cnt + (s[i] == t1 ? 1 : 0);
                    int gain = (s[i] == t2 ? cnt : 0);
                    // Special rule if t1 == t2: it counts as t2 pairing with previous t1s,
                    // BUT it also increments ncnt. We handle its contribution BEFORE incrementing.
                    if (nj <= k) {
                        dp[i + 1][nj][ncnt] = max(dp[i + 1][nj][ncnt], cur_val + gain);
                    }
                }

                // State B: Force s[i] to be t1
                {
                    int nj = j + (s[i] == t1 ? 0 : 1);
                    int ncnt = cnt + 1;
                    int gain = (t1 == t2 ? cnt : 0);
                    if (nj <= k) {
                        dp[i + 1][nj][ncnt] = max(dp[i + 1][nj][ncnt], cur_val + gain);
                    }
                }

                // State C: Force s[i] to be t2
                {
                    int nj = j + (s[i] == t2 ? 0 : 1);
                    int ncnt = cnt + (t1 == t2 ? 1 : 0);
                    int gain = cnt;
                    if (nj <= k) {
                        dp[i + 1][nj][ncnt] = max(dp[i + 1][nj][ncnt], cur_val + gain);
                    }
                }
            }
        }
    }

    int max_subsequences = 0;
        for (int cnt = 0; cnt <= n; ++cnt) {
            max_subsequences = max(max_subsequences, dp[n][k][cnt]);
        }

    cout << max_subsequences << "\n";

    return 0;
}