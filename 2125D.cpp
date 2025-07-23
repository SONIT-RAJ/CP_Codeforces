#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;
const int MOD = 998244353;

#define SUVRAT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


const int N = 2e5+1;

ll n, m;
vector <vector <ll>> v[N];
ll DP[N];


ll binex(ll a , ll b , ll mod)
{
	a %= mod;

	ll result = 1;
	b = b % (MOD-1);
	while(b > 0)
	{
		if(b%2 == 1)
			result = (result%mod * a%mod)%mod ;
		a = (a%mod*a%mod)%mod;
		b = b/2;
	}
	return result;
}


ll modinv(ll a, ll p)
{
	return (binex(a , p-2 , p) );
}


ll dp(ll i)
{
    if(i > m)
    {
        return 1;
    }
    if(DP[i] != -1) return DP[i];
    ll ans = 0;
    for(auto next: v[i])
    {
        ll r = next[0];
        ll p = next[1];
        ll q = next[2];

        ll val = 1;

        val *= modinv(q-p, MOD);
        val %= MOD;
        val *= p;
        val %= MOD;

        ans += (val * dp(r+1)) % MOD;
        ans %= MOD;
    }
    DP[i] = ans;

    return ans;
}


int main()
{
    SUVRAT
    memset(DP, -1, sizeof(DP));
    cin >> n >> m;
    ll val = 1;
    for(ll i = 0 ; i < n ; i++)
    {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        v[l].push_back({r, p, q});

        val *= (q-p);
        val %= MOD;
        val *= modinv(q, MOD);
        val %= MOD;
    }

    cout << (val*dp(1))%MOD << endl;

    return 0;
}