#include <iostream>
#include <vector>
using namespace std;

int findFirstDifferentBit(const vector<long long>& nums) {
    // We are guaranteed that nums has at least 2 distinct numbers.
    for (int bit = 0; bit < 64; bit++) { // Check each bit position from right to left.
        long long mask = (1LL << bit);
        bool foundZero = false, foundOne = false;
        for (long long num : nums) {
            if (num & mask)
                foundOne = true;
            else
                foundZero = true;
            if (foundOne && foundZero)
                return bit + 1; // return 1-indexed bit position
        }
    }
    return -1; // Should never happen if numbers are distinct.
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        bool hasEven = false, hasOdd = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // If both odd and even numbers exist, then using k = 2 works:
        // because a mod 2 yields 0 for evens and 1 for odds.
        if(hasEven && hasOdd) {
            cout << 2 << "\n";
            continue;
        }

        // Otherwise, the array is either all even or all odd.
        // For odd numbers, subtract 1 from each to make them even.
        if(hasOdd) {
            for(int i = 0; i < n; i++){
                a[i]--;
            }
        }

        // Now, all numbers are even. Find the first bit (from the right)
        // where at least two numbers differ.
        int p = findFirstDifferentBit(a);
        // Use bit shifting to compute k = 2^p
        long long ans = (1LL << p);
        // Make sure the answer does not exceed 10^18.
        const long long LIMIT = 1000000000000000000LL;
        if(ans > LIMIT) ans = LIMIT;
        cout << ans << "\n";
    }
    return 0;
}
