/*
   Author: SONIT RAJ
    created: 22:16:34 21-04-2025
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

    int n,k;
    cin>>n>>k;
    map<int,int,greater<int>>mpp;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x%k!=0){
            mpp[x%k]++;
        }
    }
    int answer=0;
    int count=0;
    int r=0;
    x=0;
    for (auto pair : mpp) {
        int key=pair.first;
        int val=pair.second;
        r=k-key-x;
        int z=val-count-1;
        if(val-count>0){
            answer+=r+1+k*z;
            count=val-1;
            x=k-key+1;
        }
    }
    cout<<answer;





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