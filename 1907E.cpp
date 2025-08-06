/*
   Author: SONIT RAJ
    created: 22:33:11 06-08-2025
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

vector<int>dp(10,0);
void pre(){
    for(int i=0;i<10;i++){
        for(int a=0;a<10;a++){
            for(int b=0;b<10;b++){
                int c=i-a-b;
                if(c>=0 && c<10){
                    dp[i]++;
                }
            }
        }
    }
}

void solve(){

    int n;
    cin>>n;
    int ans=1;
    while(n>0){
        ans*=dp[n%10];
        n/=10;
    }
    cout<<ans;



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    pre();
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}