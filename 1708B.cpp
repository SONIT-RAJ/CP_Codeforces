/*
   Author: SONIT RAJ
    created: 13:31:12 26-03-2025
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

    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n);
    unordered_map<int,bool>mpp;
    for(int i=n;i>=1;i--){
        int x=r%i;
        int y=r-x;
        while(mpp[__gcd(y,i)]==true){
            y-=i;
            if(y<l){
                cout<<"NO";
                return;
            }
        }
        if(y<l){
            cout<<"NO";
            return;
        }
        mpp[y]=true;
        a[i-1]=y;
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
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