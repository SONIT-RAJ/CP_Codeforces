#include <bits/stdc++.h>
using namespace std;

// Function to find top 3 elements and their indices
vector<pair<int, int>> findTop3(vector<int>& arr) {
    // Create a priority queue to track top 3 values and indices
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < arr.size(); i++) {
        pq.push(make_pair(arr[i], i));
    }

    vector<pair<int, int>> result;
    for (int i = 0; i < 3 && !pq.empty(); i++) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Read three arrays and find their top 3 elements
        vector<vector<pair<int, int>>> topElements(3);

        for (int arrayIdx = 0; arrayIdx < 3; arrayIdx++) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            topElements[arrayIdx] = findTop3(arr);
        }

        // Calculate best sum by trying all combinations of A, B, C arrays
        long long maxSum = 0;

        // Try all possible permutations of the three arrays
        vector<int> perm = {0, 1, 2}; // represents arrays A, B, C

        do {
            // Find the best elements from each array, ensuring no index is repeated
            set<int> usedIndices;
            long long currentSum = 0;

            for (int i = 0; i < 3; i++) {
                int arrayIdx = perm[i];

                // Try to find the best available element
                for (int j = 0; j < topElements[arrayIdx].size(); j++) {
                    int val = topElements[arrayIdx][j].first;
                    int idx = topElements[arrayIdx][j].second;

                    if (usedIndices.find(idx) == usedIndices.end()) {
                        currentSum += val;
                        usedIndices.insert(idx);
                        break;
                    }
                }
            }

            maxSum = max(maxSum, currentSum);
        } while (next_permutation(perm.begin(), perm.end()));

        cout << maxSum << endl;
    }

    return 0;
}