/*
   Author: SONIT RAJ
    created: 01:29:16 26-05-2025
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

    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>b;
    b.reserve(n);
    int c=0;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>x){
            c++;
            if((a[i]-a[i-1])%x==0){
                b.emplace_back((a[i]-a[i-1])/x-1);
            }
            else{
                b.emplace_back((a[i]-a[i-1])/x);
            }
        }
    }
    sort(b.begin(),b.end());
    int r=c+1;
    for(int i=0;i<c;i++){
        k-=b[i];
        if(k<0){
            r=i;
            break;
        }
    }
    cout<<max(1LL*1,c-r+1);




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}