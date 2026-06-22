#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// First DFS pass to order nodes by finish times
void dfs1(int u, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v, adj, visited, st);
        }
    }
    st.push(u); // Push to stack when all neighbors are processed
}

// Second DFS pass on the reversed graph to assign component IDs
void dfs2(int u, const vector<vector<int>>& adjRev, vector<bool>& visited, int componentId, vector<int>& sccMap) {
    visited[u] = true;
    sccMap[u] = componentId;
    for (int v : adjRev[u]) {
        if (!visited[v]) {
            dfs2(v, adjRev, visited, componentId, sccMap);
        }
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adjRev(n + 1);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjRev[v].push_back(u); // Reverse graph for Kosaraju'4s
        edges.push_back({u, v});
    }

    // Step 1: Kosaraju's First Pass
    vector<bool> visited(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Kosaraju's Second Pass
    fill(visited.begin(), visited.end(), false);
    vector<int> sccMap(n + 1, 0);
    int componentCount = 0;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            componentCount++;
            dfs2(u, adjRev, visited, componentCount, sccMap);
        }
    }

    // Step 3: Compute In-Degrees of the condensed components
    vector<int> inDegree(componentCount + 1, 0);
    for (const auto& edge : edges) {
        int uComp = sccMap[edge.first];
        int vComp = sccMap[edge.second];
        if (uComp != vComp) {
            inDegree[vComp]++;
        }
    }

    // Step 4: Count components with in-degree 0 (excluding the capital's component)
    int capitalComponent = sccMap[s];
    int extraRoadsNeeded = 0;
    for (int i = 1; i <= componentCount; ++i) {
        if (inDegree[i] == 0 && i != capitalComponent) {
            extraRoadsNeeded++;
        }
    }

    cout << extraRoadsNeeded << "\n";

    return 0;
}