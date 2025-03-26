/*
   Author: SONIT RAJ
    created: 21:10:12 24-03-2025
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
    int flag=0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            flag=1;
        }
    }
    if(flag==0 && s[0]==c){
        cout<<0;
        return;
    }
    if(flag==0 && s[0]!=c){
        cout<<2<<endl;
        cout<<n<<" "<<n-1;
        return;
    }
    for(int i=n-1;i>=(n+2)/2-1;i--){
        if(s[i]==c){
            cout<<1<<endl;
            cout<<i+1;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n<<" "<<n-1;
    return;



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