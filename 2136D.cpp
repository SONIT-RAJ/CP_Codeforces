/*
   Author: SONIT RAJ
    created: 18:54:17 07-09-2025
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
    int a=LLONG_MIN;
    int b=LLONG_MIN;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a=max(a,x+y);
        b=max(b,x-y);
    }
    int p1;
    cout<<"? R "<<1e9<<endl;
    cin>>p1;
    cout<<"? R "<<1e9<<endl;
    cin>>p1;
    cout<<"? R "<<1e9<<endl;
    cin>>p1;
    cout<<"? U "<<1e9<<endl;
    cin>>p1;
    cout<<"? U "<<1e9<<endl;
    cin>>p1;
    int r1=p1+a-5e9;
    cout<<"? D "<<1e9<<endl;
    cin>>p1;
    cout<<"? D "<<1e9<<endl;
    cin>>p1;
    cout<<"? D "<<1e9<<endl;
    cin>>p1;
    cout<<"? D "<<1e9<<endl;
    cin>>p1;
    int r2=p1+b-5e9;
    cout<<"! "<<(r1+r2)/2<<" "<<r1-((r1+r2)/2)<<endl;




}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}