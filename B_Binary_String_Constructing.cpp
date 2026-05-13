#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    string s = "";
    // Step 1: Decide starting character based on which count is higher
    char c1 = (a >= b) ? '0' : '1';
    char c2 = (c1 == '0') ? '1' : '0';

    // Step 2: Create base alternating string of length x + 1
    for (int i = 0; i <= x; ++i) {
        if (i % 2 == 0) {
            s += c1;
            if (c1 == '0') a--; else b--;
        } else {
            s += c2;
            if (c2 == '0') a--; else b--;
        }
    }

    // Step 3: Insert remaining characters
    // Find first '0' and '1' to dump the rest of the counts
    string res = "";
    bool addedA = false;
    bool addedB = false;

    for (char c : s) {
        res += c;
        if (c == '0' && !addedA) {
            while (a > 0) {
                res += '0';
                a--;
            }
            addedA = true;
        }
        if (c == '1' && !addedB) {
            while (b > 0) {
                res += '1';
                b--;
            }
            addedB = true;
        }
    }

    cout << res << endl;

    return 0;
}