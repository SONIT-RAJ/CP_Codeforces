/*
   Author: SONIT RAJ
    created: 12:16:32 11-04-2025
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

    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    vector<int>k(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    int maximum=LLONG_MIN;
    int answer=LLONG_MIN;
    int sum=0;
    for(int i=0;i<min(n,q);i++){
        sum+=a[i];
        maximum=max(maximum,k[i]);
        int present=sum+(q-i-1)*maximum;
        if(answer<=present){
            answer=present;
        }
    }
    cout<<answer;





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