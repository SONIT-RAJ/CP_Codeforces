/*
   Author: SONIT RAJ
    created: 10:47:55 12-09-2025
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

bool check(int mid,vector<int>&a,int n,int k,int i){
    int e=0;
    for(int j=i;j<n;j++){
        if(j==n-1){
            if(mid-j+i>a[j]){
                return false;
            }
            break;
        }
        else if(mid-j+i<=a[j]){
            break;
        }
        else{
            e+=mid-j+i-a[j];
        }
    }
    return e<=k;
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        int low=a[i];
        int high=a[i]+k;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(check(mid,a,n,k,i)){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    if(ans<a[n-1]){
        cout<<a[n-1];
        return;
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