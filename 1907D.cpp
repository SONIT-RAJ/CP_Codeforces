/*
   Author: SONIT RAJ
    created: 11:37:58 07-06-2025
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

bool check(int mid,vector<vector<int>>&a,int n){
    int left=0;
    int right=0;
    for(int i=0;i<n;i++){
        left-=mid;
        right+=mid;
        left=max(left,a[i][0]);
        right=min(right,a[i][1]);
        if(left>right){
            return false;
        }
    }
    return true;
}

void solve(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        cin>>a[i][1];
    }
    int l=0;
    int h=1e9;
    int ans=1e9;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(check(mid,a,n)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;



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