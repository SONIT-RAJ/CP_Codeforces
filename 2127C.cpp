/*
   Author: SONIT RAJ
    created: 21:14:34 07-08-2025
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
    vector<vector<int>>a(n,vector<int>(2));
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>a[i][1];
        if(a[i][1]<a[i][0]){
            swap(a[i][1],a[i][0]);
        }
        ans+=abs(a[i][0]-a[i][1]);
    }
    sort(a.begin(),a.end());
    int up=a[0][1];
    int down=a[0][0];
    int mini=INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i][0]>=down && a[i][0]<=up){
            cout<<ans;
            return;
        }
        else{
            up=a[i][1];
            down=a[i][0];
        }
    }
    up=a[0][1];
    down=a[0][0];
    for(int i=1;i<n;i++){
        mini=min(mini,2*(a[i][0]-up));
        up=a[i][1];
        down=a[i][0];
    }
    cout<<ans+mini;





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