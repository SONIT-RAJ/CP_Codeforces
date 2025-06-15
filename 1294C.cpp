/*
   Author: SONIT RAJ
    created: 20:11:37 14-06-2025
*/


#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define int long long
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rew(x) for(int i = 0; i<x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;
#define PI 3.141592653589

const int N = 1e5+1;
vector<bool> is_prime(N, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    long long n;
    cin >> n;
    long long orig = n;

    // factor counts
    unordered_map<long long, int> mpp;

    // trial divide up to sqrt(n)
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mpp[i]++;
            n /= i;
        }
    }
    // any leftover >1 is prime
    if (n > 1) {
        mpp[n]++;
    }

    // Now use your size-logic unchanged:
    if (mpp.size() >= 3) {
        cout << "YES\n";
        auto it = mpp.begin();
        long long a = it->first;  ++it;
        long long b = it->first;
        long long c = orig / (a * b);
        cout << a << " " << b << " " << c;
    }
    else if (mpp.size() == 1) {
        auto it = *mpp.begin();
        long long p = it.first, e = it.second;
        if (e >= 6) {
            // p^1, p^2, p^(e-3)
            cout << "YES\n";
            cout << p << " " << (p*p) << " " << (orig / (p*p*p));
        } else {
            cout << "NO";
        }
    }
    else if (mpp.size() == 2) {
        auto it = mpp.begin();
        long long p1 = it->first, e1 = it->second;  ++it;
        long long p2 = it->first, e2 = it->second;

        if (e1 >= 2 && e2 >= 2) {
            cout << "YES\n";
            cout << p1 << " " << p2 << " " << (orig / (p1 * p2));
        }
        else if (e1 >= 3) {
            cout << "YES\n";
            cout << p1 << " " << (p1*p1) << " " << (orig / (p1*p1*p1));
        }
        else if (e2 >= 3) {
            cout << "YES\n";
            cout << p2 << " " << (p2*p2) << " " << (orig / (p2*p2*p2));
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    sieve();
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}