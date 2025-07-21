/*
   Author: SONIT RAJ
    created: 21:53:26 21-07-2025
*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

void solve(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    ordered_set<int>s;
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        s.insert(a[i][1]);
    }
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=s.order_of_key(a[i][1]);
        s.erase(a[i][1]);
    }
    cout<<ans;



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