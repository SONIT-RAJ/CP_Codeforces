/*
   Author: SONIT RAJ
    created: 20:53:52 27-03-2025
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

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int white=0;
    for(int i=0;i<k;i++){
        if(s[i]=='W'){
            white++;
        }
    }
    int minimum=white;
    int i=0;
    int j=k-1;
    while(j<n-1 && i<n-1){
        if(s[i]=='W'){
            white--;
        }
        if(s[j+1]=='W'){
             white++;
        }
        if(minimum>white){
            minimum=white;
        }
        j++;
        i++;
    }
    cout<<minimum;




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