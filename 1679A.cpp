/*
   Author: SONIT RAJ
    created: 10:50:21 23-03-2025
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
    if(n%2!=0 || n<4){
        cout<<-1;
        return;
    }
    n/=2;
    //2x + 3y = n
    //for maximum -> we need to maximise the 4 wheel buses -> maximum x
    //for minimum -> we need to maximise the 6 wheel buses -> maximum y
    int maximum=0;
    int minimum=0;
    if(n%3==0){
        minimum=n/3;
    }
    else if(n%3==2){
        minimum=(n-2)/3+1;
    }
    else{
        minimum=(n-4)/3+2;
    }
    if(n%2==0){
        maximum=n/2;
    }
    else{
        maximum=(n-3)/2+1;
    }
        cout<<minimum<<" "<<maximum;
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