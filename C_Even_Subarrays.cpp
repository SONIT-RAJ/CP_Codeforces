/*
   Author: SONIT RAJ
    created: 11:25:16 08-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")


int ps[725];
void pre(){
    int t=0;
    for(int i=0;i*i<=(1<<19);i++){
        ps[t++]=i*i;
    }
}

int mpp[(1<<19)+1];


// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mpp[0]=1;
    int x=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        x^=a[i];
        for(int j=0;j<725;j++){
            int val=(x^ps[j]);
            ans+=mpp[val];
        }
        mpp[x]++;
    }
    long long total=(1ll*n*(n+1))/2;
    cout<<total-ans;
    mpp[0]=0;
    x=0;
    for(int i=0;i<n;i++){
        x^=a[i];
        mpp[x]=0;
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    pre();
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}