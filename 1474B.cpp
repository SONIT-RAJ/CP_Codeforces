/*
   Author: SONIT RAJ
    created: 13:23:04 26-03-2025
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

bool prime(int n){
    for(int i=2;i*i<=n;i++){if(n%i==0)  return 0;}return 1;
}
void solve(){

    int n;
    cin>>n;
    int i=n+1;
    int ans=1;
    int count=0;
    while(1){
        if(prime(i)){
            ans*=i;
            count++;
            if(count>=2){
                cout<<ans;
                return;
            }
            i+=n;
        }
        else{
            i++;
        }

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