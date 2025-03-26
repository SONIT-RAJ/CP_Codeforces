/*
   Author: SONIT RAJ
    created: 14:36:45 24-03-2025
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

    int n,p;
    cin>>n>>p;
    vector<vector<int>>a(n,vector<int>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>a[j][i];
        }
    }
    sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y) {
        return x[1] < y[1]; // Sort by second element in ascending order
    });
    int t=n-1;
    int ans=p;
    for(int i=0;i<n;i++){
        if(a[i][1]<p){
            ans+=a[i][1]*(min(a[i][0],t));
            t-=(min(a[i][0],t));
        }
        else{
            break;
        }
        if(t==0){
            break;
        }
    }
    ans+=p*(t);
    cout<<ans;



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