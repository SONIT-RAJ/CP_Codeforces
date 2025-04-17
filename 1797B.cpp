/*
   Author: SONIT RAJ
    created: 20:52:51 16-04-2025
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
    int count=0;
    vector<vector<int>>a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==a[n-i+1][n-j+1]){
                continue;
            }
            count++;
            if(count>k){
                cout<<"NO";
                return;
            }
            a[i][j]=a[n-i+1][n-j+1];
        }
    }
    if((k-count)%2==0){
        cout<<"YES";
    }
    else if(n%2==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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