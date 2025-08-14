/*
   Author: SONIT RAJ
    created: 00:33:41 15-08-2025
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
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>>b(n+1);
    for(int i=1;i<=n;i++){
        b[a[i]].emplace_back(i);
    }
    vector<int>ans(n+1,-1);
    vector<int>temp(n+1,-1);
    for(int i=1;i<=n;i++){
        int maxi=-1;
        int last=0;
        for(int j=0;j<b[i].size();j++){
            maxi=max(maxi,b[i][j]-last);
            last=b[i][j];
            if(j==b[i].size()-1){
                maxi=max(maxi,n-b[i][j]+1);
            }

        }
        temp[i]=maxi;
    }
    for(int i=1;i<=n;i++){
        if(temp[i]==-1)continue;
        int j=temp[i];
        while(j<=n && ans[j]==-1){
            ans[j++]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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