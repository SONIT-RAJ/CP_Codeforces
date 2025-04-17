/*
   Author: SONIT RAJ
    created: 21:35:23 17-04-2025
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

    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    a[0]=1;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int q=0;
    int front=a[q];
    int back=b[n-1-q];
    int i=0;
    int j=n-1;
    int count=0;
    while(i<n && j>=0){
        front=a[q];
        back=b[n-1-q];
        if(b[i]<=front || a[j]>=back){
            count++;
        }
        else{
            q++;
        }
        i++;
        j--;
    }
    cout<<count;



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