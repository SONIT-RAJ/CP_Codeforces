/*
   Author: SONIT RAJ
    created: 11:12:27 12-05-2025
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
    vector<vector<int>>a(n,vector<int>(n,-1));
    int s=n*n-1;
    int up=0;
    int down=n-1;
    int left=0;
    int right=n-1;
    while(s>=0){
        for(int j=left;j<=right;j++){
            a[up][j]=s;
            s--;
        }
        up++;
        for(int i=up;i<=down;i++){
            a[i][right]=s;
            s--;
        }
        right--;
        for(int j=right;j>=left;j--){
            a[down][j]=s;
            s--;
        }
        down--;
        for(int i=down;i>=up;i--){
            a[i][left]=s;
            s--;
        }
        left++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}