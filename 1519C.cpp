/*
   Author: SONIT RAJ
    created: 11:57:53 07-06-2025
*/

#include <bits/stdc++.h>
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

struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void solve(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>a[i][1];
    }

    sort(a.begin(), a.end(), greater<vector<int>>());


    unordered_map<int, vector<int>,CustomHash> c;

    for(int i=0;i<n;i++){
        if(c[a[i][0]].empty()){
            c[a[i][0]].push_back(0);
        }
        c[a[i][0]].push_back(a[i][1]);
    }
// Prefix sum
for (auto &[i, vec] : c) {
    for (int j = 2; j < vec.size(); j++) {
        vec[j] += vec[j - 1];
    }
}

// Answer
for (int k = 1; k <= n; k++) {
    int ans = 0;
    for (auto &[i, vec] : c) {
        int size = vec.size() - 1;
        ans += vec[size - (size % k)];
    }
    cout << ans << " ";
}

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
