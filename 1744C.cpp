/*
   Author: SONIT RAJ
    created: 13:21:10 26-03-2025
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
    char c;
    cin>>c;
    string s;
    cin>>s;
    s+=s;
    int count=0;
    int maximum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='g'){
            if(maximum<count){
                maximum=count;
            }
            count=0;
        }
        else if(count==0 && s[i]==c){
            count=1;
        }
        else if(count!=0){
            count++;
        }
    }
    cout<<maximum;




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