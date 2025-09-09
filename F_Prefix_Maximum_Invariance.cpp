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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } // n
    for (int i = 1; i <= n; i++)
        cin >> b[i]; // n

    vector<int> pga(n + 1, 0), pgb(n + 1, 0);
    vector<int> vec = {1}, val = {a[1]};
    for (int i = 2; i <= n; i++) {
        while (vec.size() && a[vec.back()] < a[i])
            vec.pop_back(), val.pop_back();
        if (vec.size()) {
            pga[i] = vec.back();
            int lo = 0, hi = val.size() - 1, j = 0;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (val[mid] >= b[i]) {
                    j = vec[mid];
                    lo = mid + 1;
                } else
                    hi = mid - 1;
            } // logn
            pgb[i] = j;
        }
        vec.push_back(i);
        val.push_back(a[i]);
    } // n*logn

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == a[i])
            ans += i * (n - i + 1);
        else if (b[i] > a[i])
            ans += pgb[i] * (n - i + 1);
        else
            ans += pga[i] * (n - i + 1);
    } // n
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