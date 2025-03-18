#include<bits/stdc++.h>
using namespace std;

long long safe_abs(long long x) {
    return x >= 0 ? x : -x;
}

long long dist(const vector<int>& p1, const vector<int>& p2) {
    // Calculate each component separately to avoid any overflow
    long long dx = safe_abs(1LL * p1[0] - 1LL * p2[0]);
    long long dy = safe_abs(1LL * p1[1] - 1LL * p2[1]);
    return dx + dy;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--; // Convert to 0-indexed
        b--; // Convert to 0-indexed

        vector<vector<int>> p(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cin >> p[i][j];
            }
        }

        // Direct cost from a to b
        long long direct_cost = dist(p[a], p[b]);

        // If there are no special cities (k=0), just output the direct cost
        if(k == 0) {
            cout << direct_cost << endl;
            continue;
        }

        // Find min cost from a to any special city
        long long fa = LLONG_MAX;
        for(int i = 0; i < k; i++){
            fa = min(fa, dist(p[a], p[i]));
        }

        // Find min cost from b to any special city
        long long fb = LLONG_MAX;
        for(int i = 0; i < k; i++){
            fb = min(fb, dist(p[b], p[i]));
        }

        // The answer is the minimum of direct path or path through special cities
        cout << min(direct_cost, fa + fb) << endl;
    }
    return 0;
}