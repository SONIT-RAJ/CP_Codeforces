/*
   Author: SONIT RAJ
    created: 18:53:03 06-07-2025
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

int sum(vector<vector<int>>&a,int n,int m){
    int s=0;
    sort(a.begin(),a.end());
    vector<vector<int>>d=a;
    vector<int>e;
    e.reserve(n*m);
    for(int i=0;i<n*m;i++){
        int back=(i!=0 && d[i][0]==d[i-1][0])?a[i-1][1]:0;
        a[i][1]+=back;
        if(i!=n*m-1 && d[i][0]!=d[i+1][0]){
            e.push_back(i);
        }
    }
    e.push_back(n*m-1);
    int i=0;
    int j=0;
    while(i<n*m && j<e.size()){
        if(i==e[j]){
            j++;
            i++;
            continue;
        }
        s+=a[e[j]][1]-a[i][1]-(d[i][1]*(e[j]-i));
        i++;
    }
    return s;
}

void solve(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n*m,vector<int>(2));
    vector<vector<int>>b(n*m,vector<int>(2));
    int c;
    int x;
    int y;
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            a[t][0]=c;
            a[t][1]=i;
            b[t][0]=c;
            b[t][1]=j;
            t++;
        }
    }
    int d=sum(a,n,m)+sum(b,n,m);
    cout<<d;





}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}