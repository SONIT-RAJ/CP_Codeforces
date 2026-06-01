#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e7 + 5;
int prime_count[MAX];

void sieve()
{
    for (int i = 2; i < MAX; i++)
        if (prime_count[i] == 0)
            for (int j = i; j < MAX; j += i)
                prime_count[j]++;
}

void solve()
{
    long long c, d, x;
    cin >> c >> d >> x;
    long long ans = 0;

    for (long long g = 1; g * g <= x; g++)
    {
        if (x % g == 0)
        {
            long long val1 = (x / g) + d;
            if (val1 % c == 0)
            {
                long long k1 = val1 / c;
                ans += (1LL << prime_count[k1]);
            }

            if (g * g != x)
            {
                long long g2 = x / g;
                long long val2 = (x / g2) + d;
                if (val2 % c == 0)
                {
                    long long k2 = val2 / c;
                    ans += (1LL << prime_count[k2]);
                }
            }
        }
    }
    cout << ans;
}

signed main()
{
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve(); // Run precomputation once

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}