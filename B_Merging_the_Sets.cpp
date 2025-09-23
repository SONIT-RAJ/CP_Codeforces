/*
   Author: SONIT RAJ
    created: 22:17:31 21-09-2025
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
    map<int,vector<int>>mpp;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        for(int j=0;j<l;j++){
            int x;
            cin>>x;
            mpp[x].push_back(i);
        }
    }
    set<int>s;
    for(int i=1;i<=m;i++){
        if(mpp[i].empty()){
            cout<<"NO";
            return;
        }
        if(mpp[i].size()==1){
            s.insert(mpp[i][0]);
        }
    }
    if(n-s.size()>=2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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