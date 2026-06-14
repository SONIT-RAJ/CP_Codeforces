#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    if (!(cin >> n >> k >> q)) return 0;

    // Step 1: Use a map for the coordinate-compressed difference array
    map<int, int> d;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }

    // Step 2: Traverse the map to find intervals where recipe count >= k
    vector<pair<int, int>> intervals;
    int active = 0;
    int start = -1;

    for (auto const& [key, val] : d) {
        int next_active = active + val;

        if (active < k && next_active >= k) {
            start = key; // A valid interval starts here
        } else if (active >= k && next_active < k) {
            intervals.push_back({start, key - 1}); // A valid interval ends here
        }
        active = next_active;
    }

    // Step 3: Create a prefix sum of the total valid points up to each interval
    vector<int> pref_len(intervals.size() + 1, 0);
    for (size_t i = 0; i < intervals.size(); i++) {
        pref_len[i + 1] = pref_len[i] + (intervals[i].second - intervals[i].first + 1);
    }

    // Helper lambda function to count valid points from -infinity up to coordinate x
    auto query = [&](int x) {
        if (intervals.empty() || x < intervals[0].first) return 0;

        // Binary search to find the first interval that starts strictly after x
        auto it = upper_bound(intervals.begin(), intervals.end(), make_pair(x, 2e9));
        int idx = distance(intervals.begin(), it) - 1; // Last interval starting <= x

        int ans = pref_len[idx]; // Add lengths of all fully covered intervals before idx

        // Handle the interval at idx
        if (x >= intervals[idx].second) {
            ans += (intervals[idx].second - intervals[idx].first + 1); // Fully covered
        } else {
            ans += (x - intervals[idx].first + 1); // Partially covered up to x
        }
        return ans;
    };

    // Step 4: Answer the queries efficiently in O(log(intervals))
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(b) - query(a - 1) << "\n";
    }

    return 0;
}