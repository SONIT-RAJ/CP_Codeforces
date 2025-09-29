#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    i64 ans = 1E18;
    for (auto c : {'a', 'b'}) {
        std::vector<int> p;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                p.push_back(i);
            }
        }
        if (p.empty()) {
            continue;
        }
        int m = p[p.size() / 2];
        i64 res = 0;
        for (int i = 0; i < p.size(); i++) {
            res += std::abs(m + i - int(p.size()) / 2 - p[i]);
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
