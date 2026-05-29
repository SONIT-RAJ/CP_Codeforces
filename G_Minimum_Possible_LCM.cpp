/*
   Author: SONIT RAJ
    created: 09:08:57 29-05-2026
*/


#include<bits/stdc++.h>
using namespace std;


// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<pair<int,int>>cnt(1e7+1,{-1,-1});
    int maxi=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxi=max(maxi,x);
        if(cnt[x].first==-1){
            cnt[x].first=i+1;
        }
        else if(cnt[x].second==-1){
            cnt[x].second=i+1;
        }
    }
    long long ans=LLONG_MAX;
    int small=1;
    int big=2;
    for(int i=1;i<=maxi;i++){
        int idx1=-1;
        int idx2=-1;
        long long val=-1;
        for(int j=i;j<=maxi;j+=i){
            if(cnt[j].first==-1)continue;
            if(idx1==-1){
                idx1=cnt[j].first;
                val=j;
                if(cnt[j].second==-1)continue;
                idx2=cnt[j].second;
                val*=j;
                break;
            }
            else{
                idx2=cnt[j].first;
                val*=j;
                break;
            }
        }
        if(idx2!=-1){
            val/=i;
            if(ans>val){
                ans=val;
                small=idx1;
                big=idx2;
            }
        }
    }
    if(small>big){
        swap(small,big);
    }
    cout<<small<<" "<<big;



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}