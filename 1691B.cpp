/*
   Author: SONIT RAJ
    created: 22:37:49 28-03-2025
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
    vector<int>a(n);
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    vector<int>ans;
    int count=0;
    for(int i=0;i<n;){
        if(mpp[a[i]]==1){
            cout<<-1;
            return;
        }
        else{
            ans.push_back(count+mpp[a[i]]);
            for(int k=1;k<mpp[a[i]];k++){
                ans.push_back(count+k);
            }
            count+=mpp[a[i]];
            i+=mpp[a[i]];
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}