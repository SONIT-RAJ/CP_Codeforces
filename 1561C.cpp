/*
   Author: SONIT RAJ
    created: 20:40:17 10-06-2025
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
    vector<vector<int>>a;
    a.reserve(n);
    int size=n;
    while(n--){
        int m;
        cin>>m;
        vector<int>b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int h=b[0]+1;
        int k=b[0]+1;
        for(int i=0;i<m;i++){
            if(k>b[i]){
                k++;
            }
            else{
                h+=b[i]-k+1;
                k=b[i]+2;
            }
        }
        a.push_back({h,m});

    }
    sort(a.begin(),a.end());
    int h=0;
    int k=h;
    for(int i=0;i<size;i++){
        if(k>=a[i][0]){
            k+=a[i][1];
        }
        else{
            h+=a[i][0]-k;
            k=a[i][0]+a[i][1];
        }
    }
    cout<<h;



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