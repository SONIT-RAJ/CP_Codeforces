/*
   Author: SONIT RAJ
    created: 11:07:13 05-09-2025
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

    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int>fa(n+1,0);
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            c++;
        }
        else{
            c=0;
        }
        fa[c]++;
    }
    for(int i=n-1;i>=1;i--){
        fa[i]+=fa[i+1];
    }
    vector<int>fb(m+1,0);
    c=0;
    for(int i=0;i<m;i++){
        if(b[i]==1){
            c++;
        }
        else{
            c=0;
        }
        fb[c]++;
    }
    for(int i=m-1;i>=1;i--){
        fb[i]+=fb[i+1];
    }
    int ans=0;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            if(i<=n && k/i<=m){
                ans+=fa[i]*fb[k/i];
            }
            if(k/i<=n && i<=m && k/i!=i){
                ans+=fa[k/i]*fb[i];
            }
        }
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