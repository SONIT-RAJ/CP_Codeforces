/*
   Author: SONIT RAJ
    created: 18:08:40 23-03-2025
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

void ans(int n,vector<int>&a){
    int l,r,k;
    cin>>l>>r>>k;
    int diff=(r==1)?a[0]:a[r-1];
    int add=(l==1)?0:a[l-2];;
    int sum=a[n-1]-diff+add;
    sum+=(k*(r-l+1));
    if(sum%2==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

void solve(){

    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            a[i]+=a[i-1];
        }
    }
    while(q--){
        ans(n,a);
        cout<<endl;
    }



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}