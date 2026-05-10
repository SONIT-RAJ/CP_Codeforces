#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> color(n + 1);
    map<int, set<int>> neighbor_colors;

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        // Initialize the map entry so colors with 0 neighbors are considered
        if (neighbor_colors.find(color[i]) == neighbor_colors.end()) {
            neighbor_colors[color[i]] = set<int>();
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int cu = color[u];
        int cv = color[v];
        if (cu != cv) {
            neighbor_colors[cu].insert(cv);
            neighbor_colors[cv].insert(cu);
        }
    }

    int max_diversity = -1;
    int best_color = -1;

    for (auto &x: neighbor_colors) {
        int col=x.first;
        auto neighbors=x.second;
        int current_diversity = neighbors.size();

        // Map is sorted by 'col' automatically, so the first
        // one we find with max_diversity will be the minimum color.
        if (current_diversity > max_diversity) {
            max_diversity = current_diversity;
            best_color = col;
        }
    }

    cout << best_color << endl;

    return 0;
}