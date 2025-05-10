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
    map<int,int>mpp;
    int x;
    for(int i=1;i<=(n*(n-1)/2);i++){
        cin>>x;
        mpp[x]++;
    }
    x=n-1;
    int c=0;
    auto it = mpp.begin();
    while(it!=mpp.end()) {
        cout<<it->first<<" ";
        c++;
        it->second=max(1LL*0,it->second-x);
        if(it->second==0){
            ++it;
        }
        x--;
    }
    for(int i=1;i<=n-c;i++){
        cout<<1000000000<<" ";
    }



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