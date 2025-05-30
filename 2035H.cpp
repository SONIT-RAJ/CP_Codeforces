#include <bits/stdc++.h>
using namespace std;

// 0-based perform: op(i+1) in problem
void perform(vector<int>& a, int i) {
    int n = a.size();
    if (i > 0) {
        int tmp = a[i-1];
        for (int j = i-1; j > 0; --j)
            a[j] = a[j-1];
        a[0] = tmp;
    }
    if (i < n-1) {
        int tmp = a[n-1];
        for (int j = n-1; j > i+1; --j)
            a[j] = a[j-1];
        a[i+1] = tmp;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        // n<=2 is trivial:
        if (n <= 2) {
            cout << (a==b ? 0 : -1) << "\n";
            continue;
        }

        // fast multiset check
        {
            auto ta = a, tb = b;
            sort(ta.begin(), ta.end());
            sort(tb.begin(), tb.end());
            if (ta != tb) {
                cout << -1 << "\n";
                continue;
            }
        }

        vector<int> ops;
        // Place b[j] into a[j], for j = n-1 down to 0
        for (int j = n-1; j >= 0; --j) {
            if (a[j] == b[j]) continue;
            int pos = find(a.begin(), a.end(), b[j]) - a.begin();

            // If pos is exactly j-1, op(pos) might be a no-op on a tiny segment.
            // In that case, shift from the other side by doing op(pos-1) first.
            int first = pos;
            if (pos == j-1)
                first = pos - 1;  // guaranteed >= 0 because j>=1

            ops.push_back(first + 1);
            perform(a, first);

            // now our target is somewhere in the big suffix/prefix cycle—finally push it to j
            ops.push_back(j + 1);
            perform(a, j);
        }

        // Done
        if (a == b && (int)ops.size() <= 2*n) {
            cout << ops.size() << "\n";
            for (int x : ops) cout << x << " ";
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
