#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS

ll que(vector<ll>& v) {
    cout << "? " << v.size() << ' ';
    for(auto x : v) {
        cout << x + 1 << ' ';
    }
    cout << endl;
    ll ans;
    cin >> ans;
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans(2*n);
    vector<ll> query(1,0);
    for(int i = 1; i < 2*n; i++) {
        query.push_back(i);
        auto an = que(query);
        if(an) {
            ans[i] = an;
            query.pop_back();
        }
    }
    query.clear();
    query.push_back(2 * n - 1);
    for(int i = 2 * n - 2; i >= 0; i--) {
        query.push_back(i);
        if(ans[i]) continue;
        auto an = que(query);
        ans[i] = an;
        query.pop_back();
    }

    cout << "! ";
    for(auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
}

int main()
{
#ifdef PRADY
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    clock_t T = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

#ifdef PRADY
    cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
#endif
    return 0;
}
