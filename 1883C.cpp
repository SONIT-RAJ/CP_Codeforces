/*
   Author: SONIT RAJ
    created: 21:32:12 23-03-2025
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
    vector<int>a(n);
    int minimum=5;
    int countEven=0;
    if(k==4){
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0){
                countEven++;
            }
            if(a[i]%k==0){
                minimum=0;
            }
            if(minimum>k-(a[i]%k)){
                minimum=k-a[i]%k;
            }
        }
        if(countEven>=2)cout<<0;
        else if(countEven==1)cout<<min(minimum,(int)1);
        else cout<<min(minimum,(int)2);
        return;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%k==0){
            minimum=0;
        }
        else if(minimum>k-(a[i]%k)){
            minimum=k-a[i]%k;
        }
    }
    cout<<minimum;





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