/*
   Author: SONIT RAJ
    created: 23:08:07 16-05-2025
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

    int n,x;
    cin>>n>>x;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    int y=0;
    int ans=0;
    for(int i=n;i>=1;i--){
        if(p[i]>x){
            continue;
        }
        else{
            int days=(x-p[i])/i +1;
            if(days>y){
                ans+=i*(days-y);
                y=days;
            }
        }
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