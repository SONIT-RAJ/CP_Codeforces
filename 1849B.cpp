/*
   Author: SONIT RAJ
    created: 13:58:52 28-03-2025
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

bool customSort(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1])
        return a[0] < b[0]; // If second elements are equal, sort by first element in increasing order
    return a[1] > b[1]; // Otherwise, sort by second element in decreasing order
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        a[i][0]=i+1;
        int x;
        cin>>x;
        a[i][1]=x%k;
    }
    sort(a.begin(), a.end(), customSort);
    for(int i=0;i<n;i++){
        if(a[i][1]==0){
            cout<<a[i][0]<<" ";
        }
    }
    for(int j=0;j<n;j++){
        if(a[j][1]==0){
            break;
        }
        cout<<a[j][0]<<" ";
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