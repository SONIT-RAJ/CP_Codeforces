// -- Meow --
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

// -------------------- Debugger --------------------
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ", _print(x), cerr << '\n'
#else
#define debug(x...)
#endif

void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }

template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (auto &i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "{ ";
    for (auto &i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}
template <class T, class V>
void _print(map<T, V> m)
{
    cerr << "{ ";
    for (auto &i : m)
    {
        cerr << i.first << ":";
        _print(i.second);
        cerr << " ";
    }
    cerr << "}";
}
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "(";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << ")";
}
void _print() {}
template <class T, class... V>
void _print(T t, V... v)
{
    _print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
// --------------------------------------------------

struct FastIO
{
    FastIO()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;
// --------------------------------------------------

//----------------Some lallu Tips :)-------------------

// Read the question properly.
// At least dry run 1 test case on pen & paper.
// Always check edge cases and t == 1
// If problem involves min/max  → think Binary Search?
// If 10 minutes pass and no hint → change the approach.
// If direct solution not clicking → try thinking in reverse (ulta soch).
// Always use 1LL * for multiplication to avoid overflow.

// --------------------------------------------------

// 3  4  2
// 4. 2. 7

class SegmentTree
{
public:
    int n;
    vector<pair<bool, int>> seg;

    SegmentTree(int n)
    {
        this->n = n;
        seg.assign(4 * n, {0, 0});
    }

    pair<bool, int> merge(const pair<bool, int> &a, const pair<bool, int> &b)
    {
        if (!a.first && !b.first)
            return {0, 0};
        if (b.first)
            return b;
        return a;
    }

    pair<bool, int> query(int i, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return {0, 0};
        if (l >= ql && r <= qr)
            return seg[i];
        int mid = l + ((r - l) >> 1);
        return merge(query(2 * i + 1, l, mid, ql, qr), query(2 * i + 2, mid + 1, r, ql, qr));
    }

    void pointUpdate(int i, int l, int r, int pmVal, int idx, bool val)
    {
        if (l == r)
        {
            if (val == 1)
                seg[i] = {1, idx};
            return;
        }
        int mid = l + ((r - l) >> 1);
        if (pmVal <= mid)
            pointUpdate(2 * i + 1, l, mid, pmVal, idx, val);
        else
            pointUpdate(2 * i + 2, mid + 1, r, pmVal, idx, val);
        seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }
};
// --------------------------------------------------

ll n;
vector<ll> a, b, c;
// 4 3 2 1
// 5 4 3 2 1
// 7 6

void sol()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (ll &x : a)
        cin >> x;
    for (ll &x : b)
        cin >> x;
    for (ll &x : c)
        cin >> x;

    SegmentTree sta(n + 1), stb(n + 1), stc(n + 1);
    vector<bool> dp(n, 0);
    dp[n - 1] = 1;
    sta.pointUpdate(0, 0, n, a[n - 1], n - 1, 1);
    stb.pointUpdate(0, 0, n, b[n - 1], n - 1, 1);
    stc.pointUpdate(0, 0, n, c[n - 1], n - 1, 1);

    // wo idx ka next idx and 1 2 or 3
    vector<pii> travel(n);

    for (int x = n - 1; x >= 0; x--)
    {
        // for (int i = x + 1; i < n; i++)
        // {
        //     if (a[x] > a[i] && dp[i])
        //         dp[x] = 1;
        //     else if (b[x] > b[i] && dp[i])
        //         dp[x] = 1;
        //     else if (c[x] > c[i] && dp[i])
        //         dp[x] = 1;
        // }

        // a mein check kar
        {
            auto check = sta.query(0, 0, n, 1, a[x] - 1);
            // debug(check);
            if (check.first)
            {
                travel[x] = {check.second, 1};
                dp[x] = 1;
                sta.pointUpdate(0, 0, n, a[x], x, dp[x]);
                stb.pointUpdate(0, 0, n, b[x], x, dp[x]);
                stc.pointUpdate(0, 0, n, c[x], x, dp[x]);
                continue;
            }
        }
        {
            auto check = stb.query(0, 0, n, 1, b[x] - 1);
            // debug(check);
            if (check.first)
            {
                travel[x] = {check.second, 2};
                dp[x] = 1;
                sta.pointUpdate(0, 0, n, a[x], x, dp[x]);
                stb.pointUpdate(0, 0, n, b[x], x, dp[x]);
                stc.pointUpdate(0, 0, n, c[x], x, dp[x]);
                continue;
            }
        }
        {
            auto check = stc.query(0, 0, n, 1, c[x] - 1);
            // debug(check);
            if (check.first)
            {
                travel[x] = {check.second, 3};
                dp[x] = 1;
                sta.pointUpdate(0, 0, n, a[x], x, dp[x]);
                stb.pointUpdate(0, 0, n, b[x], x, dp[x]);
                stc.pointUpdate(0, 0, n, c[x], x, dp[x]);
                continue;
            }
        }
    }

    if (!dp[0])
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<pair<char, int>> route;
    int idx = 0;
    while (idx != n - 1)
    {
        if (travel[idx].second == 1)
            route.pb({'q', travel[idx].first + 1});
        else if (travel[idx].second == 2)
            route.pb({'k', travel[idx].first + 1});
        else if (travel[idx].second == 3)
            route.pb({'j', travel[idx].first + 1});
        idx = travel[idx].first;
    }
    cout << sz(route) << endl;
    for (auto &[a, b] : route)
        cout << a << " " << b << endl;
}
// q k j
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        sol();
    return 0;
}