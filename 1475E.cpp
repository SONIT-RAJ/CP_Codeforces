/*
   Author: SONIT RAJ
    created: 20:35:15 12-08-2025
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

vector<vector<int>>ncr(1001,vector<int>(1001));
void pre(){
    ncr[0][0]=1;
            ncr[1][1]=1;
            ncr[1][0]=1;
            for(int i=2;i<=1000;i++){
                ncr[i][0]=1;
                ncr[i][i]=1;
                for(int j=1;j<i;j++){
                    ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%M;  //recurrence relation of ncr
                }
            }
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans=1;
    for(int i=0;i<n;){
        if(k>mpp[a[i]]){
            k-=mpp[a[i]];
            i+=mpp[a[i]];
        }
        else{
            int N=mpp[a[i]];
            int R=k;
            cout<<ncr[N][R]%M;
            return;
        }
    }



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    pre();
    while(t--){
        solve();
        cout<<"\n";
    }
}