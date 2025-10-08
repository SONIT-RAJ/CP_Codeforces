/*
   Author: SONIT RAJ
    created: 23:08:35 08-10-2025
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

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int r = 0; r < 2; r++) {
      vector<int> b(n);
      b[0] = r;
      for (int i = 1; i < n; i++) {
        b[i] = 1 - (b[i - 1] + a[i] - a[i - 1]);
      }
      int mn = *min_element(b.begin(), b.end());
      int mx = *max_element(b.begin(), b.end());
      if (0 <= mn && mx <= 1) {
        int cnt = 1 + accumulate(b.begin() + 1, b.end(), 0);
        if (cnt == a[0]) {
          ans += 1;
        }
      }
    }
    cout << ans;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}