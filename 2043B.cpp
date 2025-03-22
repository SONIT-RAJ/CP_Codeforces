#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;

    cout << 1 << " ";  // 1 is always included

    if ((d % 3 == 0) || (n > 2)) {
        cout << 3 << " ";
    }
    if (d == 5) {  // Include 5 only if d is exactly 5
        cout << 5 << " ";
    }
    if ((d == 7) || (n > 2)) {
        cout << 7 << " ";
    }

    if ((d == 9) || (n > 5)) {
        cout << 9 << " ";
    }
    else if((d%3==0) && (n>2)){
        cout << 9 << " ";
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
