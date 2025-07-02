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
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>b(n+1,0);
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>b[i];
        p[i]=b[i]+p[i-1];
    }
    vector<int>r(n+1,0);
    vector<int>d(n+1,0);
    for(int i=1;i<=n;i++){
        auto it=upper_bound(p.begin()+i,p.end(),a[i]+p[i-1]);
        int idx=it-p.begin();
        if(idx<=n){
            r[idx]+=a[i]-(p[idx-1]-p[i-1]);
            d[i]++;
            d[idx]--;
        }
        else{
            d[i]++;
        }

    }
    for(int i=1;i<=n;i++){
        int j=r[i];
        d[i]+=d[i-1];
        j+=b[i]*d[i];
        cout<<j<<" ";
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