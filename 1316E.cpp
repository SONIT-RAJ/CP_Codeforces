#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll mod = 1e9 + 7,inf = 1e18;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n = 1e5 + 5,p = 7,k;
vvl dp(n,vl(1<<p,-1));
vvl s(n,vl(p));
vl a(n);

ll solve(int i,int mask)
{
    if (i == n){
        if (mask != (1<<p) - 1)return -inf;
        return 0;
    }
    if (dp[i][mask] != -1)return dp[i][mask];

    int audience = i - __builtin_popcount(mask);

    ll ans = solve(i + 1,mask) + (audience >= k ? 0 : a[i]);

    for (int j = 0;j<p;j++){
        if (mask & (1<<j))continue;
        ans = max(ans,solve(i + 1,mask | (1<<j)) + s[i][j]);
    }

    return dp[i][mask] = ans;
}
int main()
{
    cin>>n>>p>>k;
    for (int i = 0;i<n;i++)cin>>a[i];

    vvl b(n);
    for (int i = 0;i<n;i++){
        b[i].push_back(a[i]);
        for (int j = 0;j<p;j++){
            ll x;
            cin>>x;
            b[i].push_back(x);
        }
    }

    sort(b.rbegin(),b.rend());

    for (int i = 0;i<n;i++){
        a[i] = b[i][0];
        for (int j = 0;j<p;j++)
            s[i][j] = b[i][j + 1];
    }

    cout<<solve(0,0);
    return 0;
}