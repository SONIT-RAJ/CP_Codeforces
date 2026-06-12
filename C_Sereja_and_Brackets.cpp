#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent each node in the Segment Tree
struct Node {
    int ans;   // Length of the maximum correct bracket subsequence
    int open;  // Number of unmatched '('
    int close; // Number of unmatched ')'
};

const int MAXN = 1000005;
string s;
Node tree[4 * MAXN];

// Function to merge two nodes
Node merge(Node L, Node R) {
    Node parent;
    int new_matches = min(L.open, R.close);

    parent.ans = L.ans + R.ans + 2 * new_matches;
    parent.open = L.open + R.open - new_matches;
    parent.close = L.close + R.close - new_matches;

    return parent;
}

// Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        // Base case: Single character leaf node
        if (s[start - 1] == '(') {
            tree[node] = {0, 1, 0};
        } else {
            tree[node] = {0, 0, 1};
        }
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    // Combine the children
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

// Query the segment tree for the range [l, r]
Node query(int node, int start, int end, int l, int r) {
    // If the current segment is completely outside the query range
    if (r < start || end < l) {
        return {0, 0, 0}; // Neutral element
    }

    // If the current segment is completely inside the query range
    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    Node L = query(2 * node, start, mid, l, r);
    Node R = query(2 * node + 1, mid + 1, end, l, r);

    return merge(L, R);
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> s)) return 0;

    int n = s.length();
    build(1, 1, n);

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Query the tree and print the 'ans' property of the result
        Node result = query(1, 1, n, l, r);
        cout << result.ans << "\n";
    }

    return 0;
}