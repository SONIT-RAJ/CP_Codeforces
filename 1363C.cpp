/*
   Author: SONIT RAJ
    created: 00:01:42 10-06-2025
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

    int n,x;
    cin>>n>>x;
    vector<bool>a(n+1,false);
    int p,q;
    for(int i=1;i<n;i++){
        cin>>p;
        cin>>q;
        if(p==x){
            a[q]=true;
        }
        else if(q==x){
            a[p]=true;
        }
    }
    if(n<=1){
        cout<<"Ayush";
        return;
    }
    int c=0;
    for(int i=1;i<=n;i++){
        if(i==x){
            continue;
        }
        if(a[i]==false){
            c++;
        }
    }
    int r=n-1-c;
    if(c%2==0){
        if(r%2==0){
            cout<<"Ashish";
        }
        else{
            cout<<"Ayush";
        }
    }
    else{
        if(r%2==0 || r==1){
            cout<<"Ayush";
        }
        else{
            cout<<"Ashish";
        }
    }




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