#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Count frequency of each element
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }

        // Check if solution is possible
        if (freq.size() > 2) {
            // More than 2 distinct values, impossible
            cout << "NO" << endl;
        }
        else if (freq.size() <= 1) {
            // Only one value, always possible
            cout << "YES" << endl;
        }
        else {
            // Exactly 2 distinct values
            auto it = freq.begin();
            int val1 = it->first;
            int count1 = it->second;

            it++;
            int val2 = it->first;
            int count2 = it->second;

            // Check if counts differ by at most 1
            if (abs(count1 - count2) <= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}