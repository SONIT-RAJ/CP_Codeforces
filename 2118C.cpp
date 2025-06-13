/*
   Author: SONIT RAJ
    created: 10:45:11 13-06-2025
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

int countSetBits(int n) {
    return __builtin_popcountll(n);
}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=countSetBits(a[i]);
    }
    for(int i=0;i<=64;i++){
        int p=(1LL<<i);
        if(p>k || k==0){
            break;
        }
        for(int j=0;j<n;j++){
            if((a[j]&p)!=p){
                if(p<=k){
                    k-=p;
                    ans++;
                    a[j]+=p;
                }
                else{
                    break;
                }
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