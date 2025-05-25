/*
   Author: SONIT RAJ
    created: 00:40:48 26-05-2025
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
    vector<int>a(n);
    map<int,int>mpp;
    map<int,bool>mpp2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]%m]++;
    }

    int c=0;
    for (auto& pair : mpp) {
        int r=pair.first;
        if(r==0){
            c++;
            continue;
        }
        int rn=pair.second;
        int f=m-r;
        if(mpp2[f]==true){
            continue;
        }
        if(r==f){
            c++;
            continue;
        }
        int fn=mpp[f];
        int mini=min(rn,fn);
        c++;
        c+=max(1LL*0,max(rn,fn)-mini-1);
        mpp2[r]=true;
    }
    cout<<c;




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