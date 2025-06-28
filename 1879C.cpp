/*
   Author: SONIT RAJ
    created: 19:32:52 28-06-2025
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

    string s;
    cin>>s;
    int n=s.size();
    int c=0;
    int sum=0;
    int pro=1;
    for(int i=0;i<n;i++){
        if(i!=0 && s[i]!=s[i-1]){
            sum++;
            pro=(pro*c)%998244353;
            c=1;
        }
        else{
            c++;
        }
    }
    sum++;
    pro=(pro*c)%998244353;
    if(n==1){
        cout<<0<<" "<<1;
        return;
    }
    for(int i=1;i<=n-sum;i++){
        pro=(pro*i)%998244353;
    }
    cout<<n-sum<<" "<<pro;




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