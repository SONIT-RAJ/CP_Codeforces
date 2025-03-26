/*
   Author: SONIT RAJ
    created: 14:56:00 24-03-2025
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
    cin>>n;
    vector<int>a;
    vector<int>c;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int>b(m);
        for(int j=0;j<m;j++){
            cin>>b[j];
        }
        sort(b.begin(),b.end());
        a.push_back(b[0]);
        c.push_back(b[1]);
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    int sum=a[0];
    for(int i=1;i<c.size();i++){
        sum+=c[i];
    }
    cout<<sum;



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}