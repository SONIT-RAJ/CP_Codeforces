#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, l, r; cin >> n >> k >> l >> r;

    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    auto f = [&](int k){
        int dis = 0;
        map <int, int> cnt;
        int e = 0;
        int ans = 0;

        for (int i = 1; i <= n; i++){
            while (e + 1 <= n && dis < k){
                e++;
                cnt[a[e]]++;
                dis += cnt[a[e]] == 1;
            }

            if (dis == k){
                int L = e - i + 1;
                int R = n - i + 1;

                L = max(L, l);
                R = min(R, r);

                ans += max(0LL, R - L + 1);
            }

            cnt[a[i]]--;
            dis -= cnt[a[i]] == 0;
        }
        return ans;
    };

    int ans = f(k);
    ans -= f(k + 1);

    cout << ans << "\n";
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}