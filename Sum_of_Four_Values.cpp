/*
   Author: SONIT RAJ
    created: 13:41:57 08-10-2025
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

    int n,t;
    cin>>n>>t;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(),a.end());
    int i=0;
    int j=n-1;
    while(i<j){
        int k=i+1;
        int l=j-1;
        while(k<l){
            if(a[i][0]+a[j][0]+a[k][0]+a[l][0]==t){
                cout<<a[i][1]<<" "<<a[j][1]<<" "<<a[k][1]<<" "<<a[l][1];
                return;
            }
            else if(a[i][0]+a[j][0]+a[k][0]+a[l][0]>t){
                l--;
            }
            else{
                k++;
            }
        }
        i++;
    }
    cout<<"IMPOSSIBLE";



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}