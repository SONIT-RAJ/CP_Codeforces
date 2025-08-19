/*
   Author: SONIT RAJ
    created: 21:22:34 20-08-2025
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

vector<int>c(int mid,vector<int>&a,vector<int>&time){
    int n=a.size();
    vector<int>ans(2);
    ans[0]=LLONG_MIN;
    ans[1]=LLONG_MAX;
    for(int i=0;i<n;i++){
        if(time[i]>mid){
            return {-1,-1};
        }
        int d=mid-time[i];
        ans[0]=max(a[i]-d,ans[0]);
        ans[1]=min(a[i]+d,ans[1]);
        if(ans[1]<ans[0])return {-1,-1};
    }
    return ans;

}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>time(n);
    for(int i=0;i<n;i++){
        cin>>time[i];
    }
    int iterations=30;
    int low=0;
    int high=2e8+5;
    double ans;
    vector<int>falsee={-1,-1};
    while(iterations--){
        int mid=low+(high-low)/2;
        vector<int>segment=c(mid,a,time);
        if(segment!=falsee){
            ans=(segment[0]+segment[1])/2.0;
            high=mid;
        }
        else{
            low=mid;
        }
    }
    cout<<setprecision(12)<<fixed<<ans;




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