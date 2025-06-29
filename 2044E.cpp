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

    int k,l1,r1,L2,R2;
    cin>>k>>l1>>r1>>L2>>R2;
    int p=1;
    int ans=0;
    while(p<=1e9){
        p*=k;
        int l2=ceil(1.00*L2/p);
        int r2=R2/p;
        int left=max(l2,l1);
        int right=min(r2,r1);
        int d=right-left+1;
        if(d>=0){
            ans+=d;
        }
    }
    p=1;
        int l2=ceil(1.00*L2/p);
        int r2=R2/p;
        int left=max(l2,l1);
        int right=min(r2,r1);
        int d=right-left+1;
        if(d>=0){
            ans+=d;
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