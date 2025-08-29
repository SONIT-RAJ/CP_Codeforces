/*
   Author: SONIT RAJ
    created: 00:08:25 30-08-2025
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
    for(int i=k;i<n;i++){
        if(s[i]=='1'){
            if(s[i%k]=='0'){
                cout<<"NO";
                return;
            }
            s[i%k]='1';
        }
        else if(s[i]=='0'){
            if(s[i%k]=='1'){
                cout<<"NO";
                return;
            }
            s[i%k]='0';
        }
    }
    int c1=0;
    int c2=0;
    for(int i=0;i<k;i++){
        if(s[i]=='1')c1++;
        else if(s[i]=='0') c2++;
    }
    if(c1>k/2 || c2>k/2){
        cout<<"NO";
    }
    else{
        cout<<"YES";
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