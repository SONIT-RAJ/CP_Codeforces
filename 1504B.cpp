/*
   Author: SONIT RAJ
    created: 11:00:16 24-03-2025
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
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"YES";
        return;
    }
    if(a.size()==1){
        cout<<"NO";
        return;
    }
    int c0=0;
    int c1=0;
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            if(flag){
                cout<<"NO";
                return;
            }
        }
        else{
            if((flag==0) &&( c0!=c1)){
                cout<<"NO";
                return;
            }
            flag=1;
        }
        if(a[i]=='0'){
            c0++;
        }
        else{
            c1++;
        }
        if(c0==c1){
            flag=0;
        }
    }
    if(flag==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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