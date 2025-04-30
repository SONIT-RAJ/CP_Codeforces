/*
   Author: SONIT RAJ
    created: 15:53:03 30-04-2025
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
    vector<int>b(n+1,0);
    vector<vector<int>>a(n+1,vector<int>(2,0));
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i][0]=b[i];
        a[i][1]=i;
    }
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+b[i];
    }
    vector<int>answer(n+1,-1);
    for(int i=n;i>=1;i--){
        auto it = upper_bound(b.begin(), b.end(), p[n]);
        int index = it - b.begin()-1;
        if(answer[a[index][1]]==-1){
            answer[a[i][1]]=index-1;
        }
        else{
            answer[a[i][1]]=answer[a[index][1]];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<answer[i]<<" ";
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