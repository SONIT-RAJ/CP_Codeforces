/*
   Author: SONIT RAJ
    created: 08:33:35 03-06-2025
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

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int maxi=LLONG_MIN;
    int mini=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    vector<int>b(n);
    int fl=-1;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]!=-1){
            fl=a[i]+b[i];
        }
    }
    if(fl!=-1){
        for(int i=0;i<n;i++){
            if(b[i]!=-1){
                if(fl!=a[i]+b[i]){
                    cout<<0;
                    return;
                }
            }
            else{
                if(fl-a[i]>=0 && fl-a[i]<=k){
                    continue;
                }
                cout<<0;
                return;
            }
        }
        cout<<1;
        return;
    }
    int p=maxi-mini;
    p=max(1LL*0,k-p+1);
    cout<<p;





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