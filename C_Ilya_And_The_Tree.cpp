#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
vector<int> a;
vector<vector<int>> adj;
vector<int> ans;

// DFS function to compute the maximum beauty for each vertex
void dfs(int u, int p, int g_prefix, const vector<int>& s_parent) {
    // 1. Calculate the prefix GCD including the current node
    int current_g = __gcd(g_prefix, a[u]);
    int max_beauty = current_g;

    // 2. Form the set of possible GCDs for the children
    vector<int> s_current;
    s_current.reserve(s_parent.size() + 1);

    // Case A: A vertex was already changed to 0 above, so we apply gcd with a[u]
    for (int x : s_parent) {
        int g = __gcd(x, a[u]);
        max_beauty = max(max_beauty, g);
        s_current.push_back(g);
    }

    // Case B: We choose to change the current vertex a[u] to 0
    max_beauty = max(max_beauty, g_prefix);
    s_current.push_back(g_prefix);

    // Record the maximum possible beauty for vertex u
    ans[u] = max_beauty;

    // Deduplicate the current set to keep it small (bounded by ~145 elements)
    sort(s_current.begin(), s_current.end());
    s_current.erase(unique(s_current.begin(), s_current.end()), s_current.end());

    // 3. Recurse for all children
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, current_g, s_current);
        }
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    a.resize(n + 1);
    adj.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from the root (vertex 1)
    vector<int> initial_set;
    dfs(1, 0, 0, initial_set);

    // Output the results
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}