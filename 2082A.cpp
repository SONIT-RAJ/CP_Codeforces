/*
   Author: SONIT RAJ
    created: 18:20:45 18-04-2025
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

    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    int r=0;
    int c=0;
    for(int i=0;i<n;i++){
        int xorR=0;
        for(int j=0;j<m;j++){
            xorR^=a[i][j];
        }
        if(xorR){
            r++;
        }
    }
    for(int j=0;j<m;j++){
        int xorC=0;
        for(int i=0;i<n;i++){
            xorC^=a[i][j];
        }
        if(xorC){
            c++;
        }
    }
    cout<<max(r,c);





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