/*
   Author: SONIT RAJ
    created: 09:43:28 16-06-2025
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

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    vector<vector<char>>b(n+1,vector<char>(m+1));
    char x;
    int maxi=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            b[i][j]=x;
            if(x=='g'){
                a[i][j]=1;
                maxi++;
            }
        }
    }
    vector<vector<int>>p(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
        }
    }
    int mini=LLONG_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]=='.'){
                int downx=min(n,i+k-1);
                int downy=min(m,j+k-1);
                int upx=max(1LL,i-k+1);
                int upy=max(1LL,j-k+1);
                int present=p[downx][downy]+p[upx-1][upy-1]-p[upx-1][downy]-p[downx][upy-1];
                mini=min(mini,present);
            }

        }
    }
    if(mini==LLONG_MAX){
        cout<<0;
        return;
    }
    cout<<maxi-mini;





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