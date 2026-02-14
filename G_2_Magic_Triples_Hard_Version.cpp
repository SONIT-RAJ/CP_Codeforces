/*
   Author: SONIT RAJ
    created: 21:42:20 13-02-2026
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>>f(1e6);
void pre(){
    for(int i=1;i<1e6;i++){
        for(int j=i;j<1e6;j+=i){
            f[j].push_back(i);
        }
    }
}
// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mpp;
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        mpp[a[i]]++;
    }
    int ans=0;
    for(auto &x:mpp){
        int j=x.first;
        int val=x.second;
        if(val>=3){
            ans+=(val)*(val-1)*(val-2);// for b=1
        }
        if(j>=1e6){
            for(int b=2;b*j<=maxi;b++){
                if(j%b!=0)continue;
                int i=j/b;
                int k=j*b;
                auto it1 = mpp.find(i);
                auto it2 = mpp.find(k);

                if(it1 != mpp.end() && it2 != mpp.end()){
                    ans += val * it1->second * it2->second;
                }
            }
        }
        else{
            for(int q=1;q<f[j].size();q++){
                int b=f[j][q];
                int i=j/b;
                int k=j*b;
                auto it1 = mpp.find(i);
                auto it2 = mpp.find(k);

                if(it1 != mpp.end() && it2 != mpp.end()){
                    ans += val * it1->second * it2->second;
                }
            }
        }
    }
    cout<<ans;


}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    pre();
    while(_--){
        solve();
        cout<<"\n";
    }
}