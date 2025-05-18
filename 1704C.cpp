/*
   Author: SONIT RAJ
    created: 22:06:30 17-05-2025
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

    int m,n;
    cin>>m>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>b;
    b.reserve(n);
    for(int i=0;i<n;i++){
        if(i!=n-1){
            b.emplace_back(a[i+1]-a[i]-1);
        }
        else{
            b.emplace_back(m-a[i]+a[0]-1);
        }
    }
    sort(b.begin(),b.end(),greater<int>());
    int ans=0;
    for(int i=0;i<n;i++){
        if(b[i]-(i*4)<=0){
            break;
        }
        b[i]-=(i*4);
        if(b[i]<=3){
            if(b[i]==1 || b[i]==2){
                ans++;
            }
            if(b[i]==3){
                ans+=2;
            }
            break;
        }
        else{
            ans+=b[i]-1;
        }
    }
    cout<<m-ans;




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