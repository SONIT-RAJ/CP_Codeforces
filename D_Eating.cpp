#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using namespace std;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 10000000;
#define DEBUG(x) cerr << #x << ": " << x << '\n'
template <typename T, typename Y>
istream &operator>>(istream &is, pair<T, Y> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, pair<T, Y> p)
{
    os << p.first << ' ' << p.second << ' ';
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}
vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact;
void initpow(int x)
{
    power.resize(NUM);
    power[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        power[i] = (power[i - 1] * (x % mod)) % mod;
    }
}
void initFactorial()
{
    fact.resize(NUM);
    fact[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
void calc_sieve()
{
    sieve.resize(NUM + 1, 0);
    for (int x = 2; x <= NUM; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x; u <= NUM; u += x)
        {
            sieve[u] = x;
        }
    }
}
void primefactor()
{
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}
int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}
int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}
int combination(int n, int k)
{
    if (k > n)
        return 0;
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
    return (p1 * p2) % mod;
}
typedef pair<ll, ll> Interval;
vector<Interval> mergeIntervals(vector<Interval> &intervals)
{
    if (intervals.empty())
        return {};

    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<Interval> result;
    result.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); i++)
    {
        auto &last = result.back();
        if (intervals[i].first <= last.second + 1)
        {                                                        // Overlapping or adjacent
            last.second = max(last.second, intervals[i].second); // Merge
        }
        else
        {
            result.push_back(intervals[i]); // Add new interval
        }
    }

    return result;
}
vector<Interval> intervalIntersection(vector<Interval> &set1, vector<Interval> &set2)
{
    vector<Interval> result;
    int i = 0, j = 0;
    sort(all(set1));
    sort(all(set2));
    while (i < set1.size() && j < set2.size())
    {
        int start = max(set1[i].first, set2[j].first);
        int end = min(set1[i].second, set2[j].second);

        if (start <= end)
        {
            result.push_back({start, end});
        }
        if (set1[i].second < set2[j].second)
            i++;
        else
            j++;
    }
    return result;
}
vector<Interval> valid_range(ll prev, ll curr)
{
    // prev ^ x >= curr
    vector<Interval> result;
    ll value = 0;
    for (int i = 30 - 1; i >= 0; i--)
    {
        ll currb = 0;
        ll prevb = 0;
        if (curr & (1ll << i))
        {
            currb = 1;
        }
        if (prev & (1ll << i))
        {
            prevb = 1;
        }
        if (currb)
        {
            value = value | ((1 - prevb) * (1ll << i));
        }
        else
        {
            ll lb = value | ((1 - prevb) * (1ll << i));
            ll rb = lb;
            for (int j = i - 1; j >= 0; j--)
            {
                rb |= (1ll << j);
            }
            result.push_back({lb, rb});
            value = value | ((prevb) * (1ll << i));
        }
    }
    result.push_back({value, value});
    return result;
}
bool isPresentInIntervals(const vector<Interval> &intervals, int x)
{
    int left = 0, right = intervals.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (intervals[mid].first <= x && x <= intervals[mid].second)
        {
            return true; // x is inside the interval
        }
        else if (intervals[mid].second < x)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }

    return false; // x is not in any interval
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vi v(n);
    cin >> v;
    reverse(all(v));
    ll prev = 0;
    vector<Interval> full = {{0, (1ll << 30) - 1}};
    vector<vector<Interval>> possible(n);
    for (ll i = 0; i < n; i++)
    {
        vector<Interval> vv = valid_range(prev, v[i]);
        vector<Interval> ii = mergeIntervals(vv);
        ii = intervalIntersection(ii, full);
        full = ii;
        possible[i] = ii;
        prev ^= v[i];
    }
    auto check = [&](ll d, ll x)
    {
        return isPresentInIntervals(possible[d], x);
    };
    while (q--)
    {
        ll x;
        cin >> x;
        ll lo = 0, hi = n, ans = n;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (mid == n)
            {
                break;
            }
            if (check(mid, x))
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}