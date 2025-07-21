/*
   Author: SONIT RAJ
    created: 22:54:03 21-07-2025
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
    vector<int>a(n+1,0);
    vector<int>p(n+1,0);
    map<int,int>mpp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=(a[i]^p[i-1]);
        mpp[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==(p[n]^p[i]^p[i-1])){
            cout<<"YES";
            return;
        }
        if(mpp[a[i]]>1 && a[i]==(p[n]^p[i]^p[i-1]^a[i])){
            cout<<"YES";
            return;
        }
        if(a[i]==(p[n]^p[i]^p[i-1])){
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