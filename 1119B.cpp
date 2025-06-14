/*
   Author: SONIT RAJ
    created: 18:40:52 13-06-2025
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

bool check(int mid,int h,vector<int>&a){
    vector<int> temp(a.begin(), a.begin() + mid);
    sort(temp.begin(), temp.end());
    for(int i=mid-1;i>=0;i-=2){
        h-=temp[i];
        if(h>=0){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

void solve(){

    int n,h;
    cin>>n>>h;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<n;
        return;
    }
    int low=1;
    int high=n;
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid,h,a)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans;



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}