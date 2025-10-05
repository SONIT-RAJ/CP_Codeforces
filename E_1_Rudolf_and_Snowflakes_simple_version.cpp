/*
   Author: SONIT RAJ
    created: 16:11:16 03-10-2025
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

bool check(int a,int b){
    int c=0;
    while(b%a==0){
        b/=a;
        c++;
    }
    return b==1 && c>2;
}

void solve(){

    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(check(i,n*(i-1)+1)){
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";


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