/*
   Author: SONIT RAJ
    created: 11:24:08 05-06-2025
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

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int bi=-1;
    int ci=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='b' && bi==-1){
            bi=i;
        }
        else if(s[i]=='c' && ci==-1){
            ci=i;
        }
        if(bi!=-1 && ci!=-1){
            break;
        }
    }
    while(q--){
        char x,y;
        cin>>x>>y;
        if(x<=y){
            continue;
        }
        if(x=='b'){
            if(bi==n){

            }
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