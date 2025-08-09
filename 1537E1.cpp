/*
   Author: SONIT RAJ
    created: 17:04:51 08-08-2025
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

string f(string pre,int k){
    while(pre.size()<k){
        pre+=pre;
    }
    while(pre.size()>k){
        pre.pop_back();
    }
    return pre;
}

void solve(){

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string pre;
    pre.push_back(s[0]);
    string ans=f(pre,k);
    for(int i=1;i<n;i++){
        if(s[i]>s[0])break;
        pre.push_back(s[i]);
        ans=min(ans,f(pre,k));
    }
    cout<<ans;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}