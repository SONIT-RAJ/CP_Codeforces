/*
   Author: SONIT RAJ
    created: 21:58:50 20-05-2025
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

    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int col=min(b,m-b+1);
    int row=min(a,n-a+1);
    int ans1=1;
    while(n>1){
        if(n%2==0){
            n/=2;
        }
        else{
            n/=2;
            n++;
        }
        ans1++;
    }
    while(col>1){
        if(col%2==0){
            col/=2;
        }
        else{
            col/=2;
            col++;
        }
        ans1++;
    }
    int ans2=1;
    while(m>1){
        if(m%2==0){
            m/=2;
        }
        else{
            m/=2;
            m++;
        }
        ans2++;
    }
    while(row>1){
        if(row%2==0){
            row/=2;
        }
        else{
            row/=2;
            row++;
        }
        ans2++;
    }
    cout<<min(ans1,ans2);



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