/*
   Author: SONIT RAJ
    created: 23:03:58 19-09-2025
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
    vector<int>a[n+1];
    vector<int>d(n+1,0);
    int query=n-1;
    while(query--){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x<y){
            a[u].push_back(v);
            d[v]++;
        }
        else{
            a[v].push_back(u);
            d[u]++;
        }

    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    ans.reserve(n);
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto &s:a[node]){
            d[s]--;
            if(d[s]==0){
                q.push(s);
            }
        }
    }
    vector<int>result(n+1);
    int j=1;
    for(int i=0;i<n;i++){
        result[ans[i]]=j;
        j++;
    }
    for(int i=1;i<=n;i++){
        cout<<result[i]<<" ";
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