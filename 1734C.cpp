/*
   Author: SONIT RAJ
    created: 00:25:54 17-05-2025
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
    string s;
    cin>>s;
    string s2=s;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<n;j+=i){
            if(s[j]=='0' && s2[j]=='0'){
                ans+=i;
                s[j]='1';
            }
            else if(s[j]=='1' && s2[j]=='1'){
                break;
            }
            else{
                continue;
            }
        }
    }
    cout<<ans;



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