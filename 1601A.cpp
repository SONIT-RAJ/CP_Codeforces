/*
   Author: SONIT RAJ
    created: 18:48:35 12-06-2025
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        for(int j=0;j<=30;j++){
            int p=(1<<j);
            if((a[i]&p)==p){
                mpp[j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=0;j<=30;j++){
            if(mpp[j]%i!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<i<<" ";
        }
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