/*
   Author: SONIT RAJ
    created: 18:00:28 19-07-2025
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
    string s1,s2;
    cin>>s1>>s2;
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='0'){
            zero++;
        }
        else{
            one++;
        }
    }
    for(int i=0;i<n-1;i++){
        if(zero<=0 || one<=0){
            cout<<"NO";
            return;
        }
        if(s2[i]=='1'){
            zero--;
        }
        else{
            one--;
        }
    }
    cout<<"YES";




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