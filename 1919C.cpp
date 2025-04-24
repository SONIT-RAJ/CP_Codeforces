/*
   Author: SONIT RAJ
    created: 00:42:08 24-04-2025
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
    int count=0;
    int s=n+1;
    int t=n+1;
    for(int i=0;i<n;i++){
        if(a[i]<=s && a[i]<=t){
            if(s<t){
                s=a[i];
            }
            else{
                t=a[i];
            }
        }
        else if(a[i]<=t){
            t=a[i];
        }
        else if(a[i]<=s){
            s=a[i];
        }
        else{
            count++;
            if(s<t){
                s=a[i];
            }
            else{
                t=a[i];
            }

        }
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