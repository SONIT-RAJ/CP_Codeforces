/*
   Author: SONIT RAJ
    created: 14:51:32 01-05-2025
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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int l=1;
    int r=1;
    int p1=1;
    int p2=1;
    int count=0;
    int maxi=0;
    int flag=0;
    for(int i=0;i<n;i++){
        if(i==0){
            count=1;
            p1=i+1;
            p2=i+1;
        }
        else if(b[i]>=b[i-1]){
            count++;
            p2=i+1;
        }
        else{
            count=1;
            p1=i+1;
            p2=i+1;
            flag=0;
        }
        if(b[i]!=a[i]){
            flag=1;
        }
        if(maxi<=count && flag==1){
            maxi=count;
            l=p1;
            r=p2;
        }
    }
    cout<<l<<" "<<r;


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