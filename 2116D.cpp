/*
   Author: SONIT RAJ
    created: 20:01:29 01-06-2025
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

    int n,query;
    cin>>n>>query;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>>q(query,vector<int>(3,0));
    for(int i=0;i<query;i++){
        cin>>q[i][0];
        cin>>q[i][1];
        cin>>q[i][2];
    }
    vector<int>b=a;
    for(int i=query-1;i>=0;i--){
        if(b[q[i][2]]==0){
            continue;
        }
        int p=b[q[i][2]];
        b[q[i][2]]=0;
        b[q[i][0]]=max(b[q[i][0]],p);
        b[q[i][1]]=max(b[q[i][1]],p);
    }
    vector<int>b1=b;
    for(int i=0;i<query;i++){
        b[q[i][2]]=min(b[q[i][0]],b[q[i][1]]);
    }
    if(a!=b){
        cout<<-1;
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<b1[i]<<" ";
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